QString globalStyle = "\
    QPushButton {\
        border: 1px solid #313131;\
        border-radius: 4px;\
        background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
        stop: 0 #a5a5a5, stop: 0.8 #4d4d4d, stop: 1 #545454);\
        padding: 4px 12px;\
        color: #eeeeee;\
        font-weight: bold;\
    }\
    QPushButton:disabled, QPushButton:default:disabled {\
        color: rgba(255,255,255,80);\
        border: 1px solid rgba(0,0,0,80);\
        background: none;\
    }\
    QPushButton:default:pressed, QPushButton:pressed {\
        border: 1px solid #0e5a00;\
        background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
        stop: 0 #4d8e0d, stop: 1 #5aa50f);\
    }\
    QPushButton:hover {\
        background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
        stop: 0 #a5a5a5, stop: 0.7 #4d4d4d, stop: 1 #747474);\
        color: white;\
    }\
    QPushButton:default {\
        border: 1px solid #0e5a00;\
        background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
        stop: 0 #75ce1f, stop: 0.8 #4d8e0d, stop: 1 #5aa50f);\
    }\
    QPushButton:default:hover {\
        background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
        stop: 0 #75ce1f, stop: 0.7 #4d8e0d, stop: 1 #7ac52f);\
    }\
    QDialog{\
        padding: 3.5em 2em 1em 1em;\
        background: url(:/globalStyle/work_area.png) no-repeat top left;\
        border: none;\
        font-size: 10pt;\
        min-width: 150px;\
    }\
    QMenuBar{\
        border: none;\
        font-size: 10pt;\
        color: rgb(255, 255, 255);\
        background-color: qlineargradient(spread:reflect, x1:0.5, y1:0.9, x2:0.5, y2:0,\
                                          stop:0 rgba(0, 75, 0, 255),\
                                          stop:0.5 rgba(20, 20, 20, 255));\
        selection-background-color: qlineargradient(spread:reflect, x1:0.5, y1:0.7, x2:0.5, y2:0,\
                                          stop:0 rgba(0, 75, 0, 255),\
                                          stop:0.3 rgba(21, 170, 28, 255));\
    }\
    QMenu{\
        color: rgb(230, 230, 230);\
        background: url(:/globalStyle/BG_DARK) top left;\
        selection-color: rgb(0, 0, 0);\
        selection-background-color: qlineargradient(spread:pad, x1:0.5, y1:0.96, x2:0.5, y2:0,\
                                        stop:0 rgba(209, 209, 209, 252),\
                                        stop:0.065 rgba(157, 157, 157, 255),\
                                        stop:0.130 rgba(89, 89, 89, 255),\
                                        stop:0.92 rgba(250, 250, 250, 255),\
                                        stop:1 rgba(210, 210, 210, 255));\
    }\
    QMenu:disabled{\
        color: rgb(140, 140, 140);\
    }\
    QToolBar{\
        background: url(:/globalStyle/BG_DARK) top left;\
        border: none;\
        font-size: 10pt;\
        selection-background-color: rgba(127, 127, 127, 200);\
    }\
    QWidget#centralwidget{\
        background-image: url(:/globalStyle/BG_DARK);\
    }\
    QTextBrowser{\
        font-size: 10pt;\
        background-image: url(:/globalStyle/BG_LIGHT);\
    }\
    QLineEdit{\
        border: 1px solid rgba(0, 0, 0, 215);\
    }\
    QLineEdit:focus {\
        border: 3px solid rgb(39, 95, 160);\
    }\
    /*This QTabWidget and QTabBar styling example taken from Qt Examples*/\
    QTabWidget::pane { /* The tab widget frame */\
        border-top: 2px solid #C2C7CB;\
        position: absolute;\
        top: -0.5em;\
    }\
    QTabWidget::tab-bar {\
        alignment: center;\
    }\
    /* Style the tab using the tab sub-control. Note that\
        it reads QTabBar _not_ QTabWidget */\
    QTabBar::tab {\
        background: qlineargradient(spread:reflect, x1:0.5, y1:0.9, x2:0.5, y2:0,\
                                          stop:0 rgba(0, 75, 0, 255),\
                                          stop:0.5 rgba(20, 20, 20, 255));\
        color: gray;\
        border: 2px solid #C4C4C3;\
        border-bottom-color: #C2C7CB; /* same as the pane color */\
        border-top-left-radius: 4px;\
        border-top-right-radius: 4px;\
        min-width: 8ex;\
        padding: 2px 16px;\
    }\
    QTabBar::tab:selected, QTabBar::tab:hover {\
        color: white;\
        background: qlineargradient(spread:reflect, x1:0.5, y1:0.7, x2:0.5, y2:0,\
                                          stop:0 rgba(0, 75, 0, 255),\
                                          stop:0.3 rgba(21, 170, 28, 255));\
    }\
    QTabBar::tab:selected {\
        border: 2px solid;\
        border-color: rgb(75, 215, 250)/*#9B9B9B*/;\
        border-bottom-color: #C2C7CB; /* same as pane color */\
    }\
    QTabBar::tab:!selected {\
        margin-top: 2px;\
    }\
    /* make use of negative margins for overlapping tabs */\
    QTabBar::tab:selected {\
        /* expand/overlap to the left and right by 4px */\
        margin-left: -4px;\
        margin-right: -4px;\
    }\
    QTabBar::tab:first:selected {\
        margin-left: 0; /* the first selected tab has nothing to overlap with on the left */\
    }\
    QTabBar::tab:last:selected {\
        margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\
    }\
    QTabBar::tab:only-one {\
        margin: 0; /* if there is only one tab, we don't want overlapping margins */\
    }\
    ";

/*
    QMenu::item:selected { \
        background-color: white;\
        color: black;\
    }\
    QLabel{\
        color: rgb(255, 255, 255);\
    }\

    // odd dropdown button widget
    QPushButton::menu-indicator {\
        subcontrol-origin: margin;\
        left: -7px;\
        subcontrol-position: right;\
    }\

    QPushButton:open {\ // when the button has its menu open
        background: #444444;\
        border: 1px solid #222222;\
        color: white;\
    }\

    QPushButton::menu-indicator {\
        image: url(arr_down.png);\
        subcontrol-origin: padding;\
        subcontrol-position: bottom right;\
    }\

    QPushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\
        position: relative;\
        top: 1px; left: 1px;\ // shift the arrow by 1 px
    }\
*/
