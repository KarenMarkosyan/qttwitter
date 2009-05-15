#ifndef TWEETBUBBLEWIDGET_H
#define TWEETBUBBLEWIDGET_H

#include <QWidget>

class QToolButton;
class QTextBrowser;

class TweetBubbleWidget : public QWidget
{
    Q_OBJECT

public:
    TweetBubbleWidget(QWidget *parent = 0);

private:
    QToolButton *userImageButton;
    QTextBrowser *tweetTextBrowser;
    int tweetId;

public:
    void setUserIcon(QPixmap *userIcon);
    void setTweetText(QString tweet);
    void setTweetId(int tweetId);
    int getTweetId();
};

#endif // TWEETBUBBLEWIDGET_H
