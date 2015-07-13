#-------------------------------------------------
#
# Project created by QtCreator 2015-07-09T16:34:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = Player
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mybutton.cpp

HEADERS  += mainwindow.h \
    mybutton.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
