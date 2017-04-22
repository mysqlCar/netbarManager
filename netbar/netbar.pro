#-------------------------------------------------
#
# Project created by QtCreator 2017-04-17T17:19:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = netbar
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


SOURCES += main.cpp\
        login.cpp \
    mysqlmanager.cpp \
    newcard.cpp \
    newusr.cpp \
    cpuinfo.cpp \
    recharge.cpp \
    repair.cpp \
    assign.cpp \
    myManager.cpp \
    global.cpp

HEADERS  += login.h \
    mysqlmanager.h \
    newcard.h \
    newusr.h \
    cpuinfo.h \
    recharge.h \
    repair.h \
    assign.h \
    myManager.hpp \
    mysqlTransObj.hpp \
    global.h

FORMS    += login.ui \
    mysqlmanager.ui \
    newcard.ui \
    newusr.ui \
    cpuinfo.ui \
    recharge.ui \
    repair.ui \
    assign.ui

INCLUDEPATH += F:\mysql\include\
F:\mysql\include\mysql

LIBS +=F:\mysql\lib\libmysql.lib\
F:\mysql\lib\mysqlclient.lib
