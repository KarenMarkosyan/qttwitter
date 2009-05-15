#include "tweetbubblewidget.h"
#include <QToolButton>
#include <QTextBrowser>
#include <QPixmap>
#include <QHBoxLayout>

TweetBubbleWidget::TweetBubbleWidget(QWidget *parent)
        : QWidget(parent)
{
    this->setMinimumSize(375, 76);
    this->setMaximumSize(1400, 76);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->setStyleSheet("border-radius: 6px;");

    thisWidgetLayout = new QHBoxLayout(this);
    thisWidgetLayout->setSpacing(2);
    thisWidgetLayout->setMargin(2);
    thisWidgetLayout->setSizeConstraint(QLayout::SetMinimumSize);

    userImageButton = new QToolButton(this);
    userImageButton->setAutoRaise(true);
    userImageButton->setMinimumSize(72, 72);
    userImageButton->setMaximumSize(72, 72);
    userImageButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    userImageButton->setStyleSheet("border-top-left-radius: 6px;");
    userImageButton->setStyleSheet("border-bottom-left-radius: 6px;");
    userImageButton->setStyleSheet("border-top-right-radius: 0px;");
    userImageButton->setStyleSheet("border-bottom-right-radius: 0px;");
    userImageButton->setStyleSheet("border: 2px;");
    userImageButton->setStyleSheet("border-image: url(:/globalStyle/BG_DARK)");
    userImageButton->setCursor(QCursor(Qt::PointingHandCursor));
    userImageButton->setMouseTracking(true);
    userImageButton->setFocusPolicy(Qt::NoFocus);
    userImageButton->setAutoFillBackground(false);
    QIcon userIcon;
    userIcon.addPixmap(QPixmap(":/twitter/personal.svg"), QIcon::Normal, QIcon::Off);
    userImageButton->setIcon(userIcon);
    userImageButton->setIconSize(QSize(68, 68));

    thisWidgetLayout->addWidget(userImageButton, 0, Qt::AlignLeft | Qt::AlignTop);

    tweetTextBrowser = new QTextBrowser(this);
    tweetTextBrowser->setFrameShape(QFrame::NoFrame);
    tweetTextBrowser->setLineWidth(0);
    tweetTextBrowser->setStyleSheet("font: 10pt 'Lucida Grande';");
    tweetTextBrowser->setStyleSheet("border-top-right-radius: 6px;");
    tweetTextBrowser->setStyleSheet("border-bottom-right-radius: 6px;");
    tweetTextBrowser->setStyleSheet("border-top-left-radius: 0px;");
    tweetTextBrowser->setStyleSheet("border-bottom-left-radius: 0px;");
    tweetTextBrowser->setStyleSheet("background: url(:/globalStyle/BG_DARK) top left;");
    tweetTextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tweetTextBrowser->setOpenExternalLinks(true);

    thisWidgetLayout->addWidget(tweetTextBrowser);

}

void TweetBubbleWidget::copyData(Returnables::StatusUser *statusUser)
{
    userName = statusUser->user.name;
    userScreenName = statusUser->user.screenName;
    userLocation = statusUser->user.location;
    userDescription = statusUser->user.description;
    userProfileImageUrl = statusUser->user.profileImageUrl;
    userUrl = statusUser->user.url;
    userIsProtected = statusUser->user.isProtected;
    userFollowersCount = statusUser->user.followersCount;

    tweetId = statusUser->status.id;
    tweetCreatedAt = statusUser->status.createdAt;
    tweetText = statusUser->status.text;
    tweetSource = statusUser->status.source;
    tweetTruncated = statusUser->status.truncated;
    tweetInReplyToStatusId = statusUser->status.inReplyToStatusId;
    tweetInReplyToUserId = statusUser->status.inReplyToUserId;
    tweetFavourited = statusUser->status.favorited;

    createLinks(&tweetText);

    tweetTextBrowser->setFontFamily("Lucida Grande");
    tweetTextBrowser->append("<b>" + userScreenName + "</b> from " + userLocation + " <i>says</i> \n");
    tweetTextBrowser->append(tweetText);
}

void TweetBubbleWidget::createLinks(QString *tweetText)
{
    if (!tweetText->isEmpty()) {
        int j = 0;
        int l = 0;
        int h = 0;

        //HTTP Links Creation (currently only partially implemented)
        while ((l = tweetText->indexOf("http://", l)) != -1) {
            int n;
            if ( ((n = tweetText->indexOf("; ", l+7)) != -1) || ((n = tweetText->indexOf(", ", l+7)) != -1) || ((n = tweetText->indexOf(" ", l+7)) != -1) ) {
                tweetText->insert(n, "</A>");
                tweetText->insert(l, "<A href='" + tweetText->mid(l, n-l) + "'>");
                l = n + 9 + (n-l) + 2 + 4;
            }
            else {
                tweetText->append("</A>");
                tweetText->insert(l, "<A href='" + tweetText->mid(l, (tweetText->size()-4)-l) + "'>");
                l = -1;
            }
        }

        //@replies Links Creation
        while ((j = tweetText->indexOf("@", j)) != -1) {
            int k;
            if ( ((k = tweetText->indexOf(", ", j+1)) != -1) || ((k = tweetText->indexOf("; ", j+1)) != -1) || ((k = tweetText->indexOf(": ", j+1)) != -1) || ((k = tweetText->indexOf(" ", j+1)) != -1) ) {
                tweetText->insert(k, "</A>");
                tweetText->insert(j+1, "<A href='http://www.twitter.com/" + tweetText->mid(j+1, (k-1)-j) + "'>");
                j = k + 32 + (k-j) + 2 + 4;
            }
            else {
                tweetText->append("</A>");
                tweetText->insert(j+1, "<A href='http://www.twitter.com/" + tweetText->mid(j+1, ((tweetText->size()-1)-4)-j) + "'>");
                j = -1;
            }
        }

        //Hash Search Links Creation
        while ((h = tweetText->indexOf("#", h)) != -1) {
            int d = tweetText->indexOf(" ", h+1);
            if (d != -1) {
                tweetText->insert(d, "</A>");
                tweetText->insert(h+1, "<A href='http://search.twitter.com/search?q=" + tweetText->mid(h+1, (d-1)-h) + "'>");
                h = d + 44 + (d-h) + 2 + 4;
            }
            else {
                tweetText->append("</A>");
                tweetText->insert(h+1, "<A href='http://search.twitter.com/search?q=" + tweetText->mid(h+1, ((tweetText->size()-1)-4)-h) + "'>");
                h = -1;
            }
        }
    }
}

void TweetBubbleWidget::setUserIcon(QPixmap *userIcon)
{
    //The code to add the pixmap to the icon is to be done here somehow
}
