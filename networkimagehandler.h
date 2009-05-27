#ifndef NETWORKIMAGEHANDLER_H
#define NETWORKIMAGEHANDLER_H

#include <QObject>
#include <QDebug>
#include <QBuffer>
#include <QEventLoop>
#include <QMap>
#include <QHttp>
#include <QPixmap>
#include <QUrl>
#include "Server.h"

class NetworkImageHandler : public QObject
{
    Q_OBJECT

public:
    NetworkImageHandler();
    virtual ~NetworkImageHandler();

public:
    void getImage(QString url);

public slots:
    void DataReadProgress(int done, int total); //This can be used to show a progress report
    void RequestStarted(int id); //This is not going to have as such much implementation
    void RequestFinished(int id, bool error); //This is where the final processing of the data will take place
    void Done(bool error); //This is finally connected to signal to stop the event loop

private:
    QEventLoop *m_eventLoop;
    QHttp *m_http;
    QMap<int, QBuffer *> m_buffer;

private:
    void MakeConnections();
    void responseHeaderReceived(const QHttpResponseHeader &resp);
    int MakeGetRequest(QString req);

signals:
    void QueryDone();
    void OnError(QString error);
    void OnMessageReceived(QString message);
    void OnStatusReceived(SERVER::RESP resp);
    void PixmapReceived(QPixmap pixmap);
};

#endif // NETWORKIMAGEHANDLER_H
