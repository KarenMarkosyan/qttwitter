#include "imagehandler.h"

ImageHandler::ImageHandler()
{
    m_eventLoop = new QEventLoop(this);
    m_http = new QHttp();

    MakeConnections();
}

ImageHandler::~ImageHandler()
{
    if (m_eventLoop) {
        delete m_eventLoop;
    }
    if (m_http) {
        delete m_http;
    }
}

void ImageHandler::MakeConnections()
{
    connect(m_http, SIGNAL(dataReadProgress(int,int)), this, SLOT(DataReadProgress(int,int)));
    connect(m_http, SIGNAL(requestStarted(int)), this, SLOT(RequestStarted(int)));
    connect(m_http, SIGNAL(requestFinished(int,bool)), this, SLOT(RequestFinished(int, bool)));
    connect(m_http, SIGNAL(done(bool)), this, SLOT(Done(bool)));
    connect(this, SIGNAL(QueryDone()), m_eventLoop, SLOT(quit()));
}

void ImageHandler::Done ( bool /*error*/ )
{
    emit QueryDone();
}

void ImageHandler::DataReadProgress ( int /*done*/, int /*total*/ )
{
    //emit OnMessageReceived(QString::number(done).toStdString()+" / "+QString::number(total).toStdString());
    //Here I can display a progress bar or emit signal for a progress bar somewhere
}

int ImageHandler::MakeGetRequest(QString req)
{
    int id;
    QBuffer *imageDataFromServer = new QBuffer;
    imageDataFromServer->open(QIODevice::ReadWrite);
    id = m_http->get(req, imageDataFromServer);
    m_buffer.insert(id, imageDataFromServer);

    return id;
}

void ImageHandler::RequestStarted(int /*id*/)
{
    //something can be done here depending upon implementation
}

void ImageHandler::RequestFinished(int id, bool error)
{
    QPixmap requestedPixmap;
    QHttpResponseHeader head;

    if (error) {
        emit OnError(m_http->errorString());
    }

    head = m_http->lastResponse();
    if (head.isValid()) {
        responseHeaderReceived(head);
    }

    if (m_buffer.value(id)) {
        requestedPixmap.loadFromData(m_buffer.value(id)->buffer());
    } else {
        requestedPixmap = NULL;
    }

    if (!requestedPixmap.isNull()) {
        emit PixmapReceived(requestedPixmap);
    }

    if (m_buffer.value(id)) {
        m_buffer.value(id)->close();
        delete m_buffer.value(id);
        m_buffer.insert(id, NULL);
    }
}

void ImageHandler::responseHeaderReceived(const QHttpResponseHeader &resp)
{
        switch(resp.statusCode())
        {
                case SERVER::OK:
            emit OnStatusReceived(SERVER::OK);
                        break;
                case SERVER::NOT_MODIFIED:
            emit OnStatusReceived(SERVER::NOT_MODIFIED);
                        break;
                case SERVER::BAD_REQUEST:
            emit OnStatusReceived(SERVER::BAD_REQUEST);
                        break;
                case SERVER::NOT_AUTHORIZED:
            emit OnStatusReceived(SERVER::NOT_AUTHORIZED);
                        break;
                case SERVER::FORBIDDEN:
            emit OnStatusReceived(SERVER::FORBIDDEN);
                        break;
                case SERVER::NOT_FOUND:
            emit OnStatusReceived(SERVER::NOT_FOUND);
                        break;
                case SERVER::INTERNAL_SERVER_ERROR:
            emit OnStatusReceived(SERVER::INTERNAL_SERVER_ERROR);
                        break;
                case SERVER::BAD_GATEWAY:
            emit OnStatusReceived(SERVER::BAD_GATEWAY);
                        break;
                case SERVER::SERVICE_UNAVAILABLE:
            emit OnStatusReceived(SERVER::SERVICE_UNAVAILABLE);
                        break;
                default:
            emit OnStatusReceived(SERVER::UNKNOWN);
                        break;
        }
}

void ImageHandler::getImage(QString url)
{
    MakeGetRequest(url);
    m_eventLoop->exec(QEventLoop::AllEvents);
}
