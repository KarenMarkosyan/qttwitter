//
// This file is part of the Marble Desktop Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2006-2007 Torsten Rahn <tackat@kde.org>"
// Copyright 2007      Inge Wallin  <ingwa@kde.org>"
// Copyright 2008      Jens-Michael Hoffmann <jensmh@gmx.de>
//

#include "HttpDownloadManager.h"

#include <QtCore/QDebug>

#include "HttpFetchFile.h"
#include "MarbleDirs.h"
#include "StoragePolicy.h"

HttpDownloadManager::HttpDownloadManager ( const QUrl& serverUrl, StoragePolicy *policy )
        : m_activatedJobsLimit ( 40 )
        , m_jobQueueLimit ( 1000 )
        , m_serverUrl ( serverUrl )
        , m_storagePolicy ( policy )
{
    m_downloadEnabled = true; //enabled for now

    m_jobQueue.clear();
    m_activatedJobList.clear();
    m_jobBlackList.clear();

    m_fetchFile = new HttpFetchFile ( m_storagePolicy, this );

    connect ( m_fetchFile, SIGNAL ( jobDone ( HttpJob*, int ) ), this, SLOT ( reportResult ( HttpJob*, int ) ) );
    connect ( m_fetchFile, SIGNAL ( statusMessage ( QString ) ), this, SIGNAL ( statusMessage ( QString ) ) );
}


HttpDownloadManager::~HttpDownloadManager()
{
    m_downloadEnabled = false;

    qDeleteAll ( m_jobQueue );
    m_jobQueue.clear();

    qDeleteAll ( m_activatedJobList );
    m_activatedJobList.clear();

    qDeleteAll ( m_jobBlackList );
    m_jobBlackList.clear();

    delete m_storagePolicy;
}

void HttpDownloadManager::setServerUrl ( const QUrl& serverUrl )
{
    m_serverUrl = serverUrl;
}

void HttpDownloadManager::setJobQueueLimit ( int jobQueueLimit )
{
    m_jobQueueLimit = jobQueueLimit;
}

void HttpDownloadManager::setActivatedJobsLimit ( int activatedJobsLimit )
{
    m_activatedJobsLimit = activatedJobsLimit;
}

void HttpDownloadManager::addJob ( const QString& relativeUrlString, const QString &id )
{
    if ( !m_downloadEnabled )
        return;

    QUrl sourceUrl ( m_serverUrl );
    QString path = sourceUrl.path();
    sourceUrl.setPath ( path + relativeUrlString );

    HttpJob *job = new HttpJob ( sourceUrl, relativeUrlString, id );
    if ( acceptJob ( job ) )
    {
        m_jobQueue.enqueue ( job );
        job->setStatus ( Pending );
        activateJobs();
    }
    else
    {
        delete job;
    }
}

void HttpDownloadManager::addJob ( const QUrl& sourceUrl, const QString& destFileName,
                                   const QString &id )
{
    if ( !m_downloadEnabled )
        return;
    HttpJob *job = new HttpJob ( sourceUrl, destFileName, id );
    if ( acceptJob ( job ) )
    {
        m_jobQueue.enqueue ( job );
        job->setStatus ( Pending );
        activateJobs();
    }
    else
    {
        delete job;
    }
}

bool HttpDownloadManager::acceptJob ( HttpJob  *job )
{
    QList<HttpJob*>::iterator i;

    // We update the initiatorId as the previous initiator
    // likely doesn't exist anymore

    for ( i = m_jobQueue.begin(); i != m_jobQueue.end(); ++i )
    {
        if ( job->originalDestinationFileName() == ( *i )->originalDestinationFileName() )
        {
            qDebug() << "Download rejected: It's in the queue already.";
            ( *i )->setInitiatorId ( job->initiatorId() );
            return false;
        }
    }
    for ( i = m_activatedJobList.begin(); i != m_activatedJobList.end(); ++i )
    {
        if ( job->originalDestinationFileName() == ( *i )->originalDestinationFileName() )
        {
            qDebug() << "Download rejected: It's being downloaded already.";
            ( *i )->setInitiatorId ( job->initiatorId() );
            return false;
        }
    }
    for ( i = m_jobBlackList.begin(); i != m_jobBlackList.end(); ++i )
    {
        if ( job->originalDestinationFileName() == ( *i )->originalDestinationFileName() )
        {
            qDebug() << "Download rejected: Blacklisted.";
            ( *i )->setInitiatorId ( job->initiatorId() );
            return false;
        }
    }

    return true;
}

void HttpDownloadManager::removeJob ( HttpJob* job )
{
    int pos = m_activatedJobList.indexOf ( job );

    if ( pos > 0 )
    {
        m_activatedJobList.removeAt ( pos );
        qDebug() << "Removing: " << job->initiatorId();
        delete job;
    }

    activateJobs();
}


void HttpDownloadManager::activateJobs()
{
    while ( m_jobQueue.count() > 0
            && m_activatedJobList.count() < m_activatedJobsLimit )
    {
        HttpJob  *job = m_jobQueue.dequeue();

        qDebug() << "On activatedJobList: " << job->sourceUrl().toString() << job->destinationFileName();
        m_activatedJobList.push_back ( job );
        job->setStatus ( Activated );
        m_fetchFile->executeJob ( job );
    }
}

void HttpDownloadManager::reportResult ( HttpJob* job, int err )
{
    if ( err != 0 )
    {
        int pos = m_activatedJobList.indexOf ( job );

        if ( pos >= 0 )
        {
            m_activatedJobList.removeAt ( pos );
            m_jobBlackList.push_back ( job );

            qDebug() << QString ( "Download of %1 Blacklisted. Number of blacklist items: %2" ).arg ( job->destinationFileName() ).arg ( m_jobBlackList.size() );
        }
    }
    else
    {
        qDebug() << "HttpDownloadManager: Download Complete:"
        << job->originalDestinationFileName() << job->initiatorId();
        emit downloadComplete ( job->originalDestinationFileName(), job->initiatorId() );
        removeJob ( job );
    }

}

#include "HttpDownloadManager.moc"
