#-------------------------------------------------
#
# Project created by QtCreator 2017-12-26T19:02:27
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimeAttack
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
    src/databasemanager.cpp \
    src/newrally.cpp \
    src/editdriver.cpp \
    src/editstage.cpp \
    src/listrally.cpp \
    src/rally.cpp

HEADERS += \
        src/mainwindow.h \
    src/databasemanager.h \
    src/newrally.h \
    src/editdriver.h \
    src/editstage.h \
    src/listrally.h \
    src/rally.h

FORMS += \
        src/mainwindow.ui \
    src/newrally.ui \
    src/editstage.ui \
    src/editdriver.ui \
    src/listrally.ui
