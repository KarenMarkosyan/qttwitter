#ifndef TWEETBUBBLEWIDGET_H
#define TWEETBUBBLEWIDGET_H

#include <QWidget>
#include "Returnables.h"

class QToolButton;
class QTextBrowser;
class QHBoxLayout;
class QPixmap;
class NetworkImageHandler;

class TweetBubbleWidget : public QWidget
{
    Q_OBJECT

public:
    TweetBubbleWidget(QWidget *parent = 0);

private:
    QToolButton *userImageButton;
    QTextBrowser *tweetTextBrowser;
    QHBoxLayout *thisWidgetLayout;
    NetworkImageHandler *requestImage;
    //========= User Info Variables ======================
    unsigned int userId;
    QString userName;
    QString userScreenName;
    QString userLocation;
    QString userDescription;
    QString userProfileImageUrl;
    QString userUrl;
    bool userIsProtected;
    unsigned int userFollowersCount;
    //========= Status Info Variables ====================
    unsigned int tweetId;
    QString tweetCreatedAt;
    QString tweetText;
    QString tweetSource;
    bool tweetTruncated;
    unsigned int tweetInReplyToStatusId;
    unsigned int tweetInReplyToUserId;
    bool tweetFavourited;
    //========= Utility Methods ==========================
    void createLinks(QString *tweet);

public:
    void copyData(Returnables::StatusUser *statusUser);

public slots:
    void resizeWidgets();
    void setUserIcon(QPixmap);
};

#endif // TWEETBUBBLEWIDGET_H
