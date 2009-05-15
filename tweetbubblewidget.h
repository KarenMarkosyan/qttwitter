#ifndef TWEETBUBBLEWIDGET_H
#define TWEETBUBBLEWIDGET_H

#include <QWidget>
#include "Returnables.h"

class QToolButton;
class QTextBrowser;
class QHBoxLayout;

class TweetBubbleWidget : public QWidget
{
    Q_OBJECT

public:
    TweetBubbleWidget(QWidget *parent = 0);

private:
    QToolButton *userImageButton;
    QTextBrowser *tweetTextBrowser;
    QHBoxLayout *thisWidgetLayout;
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
    void setUserIcon(QPixmap *userIcon);

public:
    void copyData(Returnables::StatusUser *statusUser);
};

#endif // TWEETBUBBLEWIDGET_H
