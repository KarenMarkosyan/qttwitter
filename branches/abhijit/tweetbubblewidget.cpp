#include "tweetbubblewidget.h"
#include <QToolButton>
#include <QTextBrowser>

TweetBubbleWidget::TweetBubbleWidget(QWidget *parent)
        : Qwidget(parent)
{
    userImageButton = new QToolButton(this);

}
