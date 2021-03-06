QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    nowqt.cpp \
    cinema.cpp \
    sport.cpp \
    kids.cpp \
    allinclusive.cpp \
    viewlistac.cpp \
    addclientwindow.cpp \
    controller.cpp \
    model.cpp \
    dettclientwindow.cpp \
    modclientwindow.cpp

HEADERS += \
    mainwindow.h \
    nowqt.h \
    kids.h \
    cinema.h \
    sport.h \
    allinclusive.h \
    viewlistac.h \
    addclientwindow.h \
    controller.h \
    model.h \
    dettclientwindow.h \
    container.h \
    deeppointer.h \
    modclientwindow.h

FORMS +=

RESOURCES += \
    risorse.qrc
