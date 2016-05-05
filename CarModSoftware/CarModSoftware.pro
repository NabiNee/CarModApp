#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T19:55:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CarModSoftware
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        system.cpp \
    user.cpp \
    userlist.cpp \
    projects.cpp \
    createaccount.cpp \
    calculator.cpp \
    make.cpp \
    parts.cpp \
    projectsnapshot.cpp

HEADERS  += system.h \
    user.h \
    userlist.h \
    projects.h \
    createaccount.h \
    calculator.h \
    make.h \
    parts.h \
    projectsnapshot.h

FORMS    += system.ui \
    projects.ui \
    createaccount.ui \
    projectsnapshot.ui

RESOURCES += \
    resources.qrc \
    resources.qrc
