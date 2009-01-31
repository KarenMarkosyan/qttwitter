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
        background-color: rgb(0, 0, 0);\
        color: rgb(255, 255, 255);\
        selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(212, 212, 212, 240), stop:0.477273 rgba(127, 127, 127, 250), stop:1 rgba(212, 212, 212, 240));\
    }\
    QMenu{\
        color: rgb(255, 255, 255);\
        alternate-background-color: rgb(127, 127, 127);\
        background: url(:/globalStyle/BG_DARK) top left;\
        selection-color: rgb(0, 0, 0);\
        selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(212, 212, 212, 240), stop:0.477273 rgba(127, 127, 127, 250), stop:1 rgba(212, 212, 212, 240));\
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
    }";

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
