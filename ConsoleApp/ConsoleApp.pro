#-------------------------------------------------
#
# Project created by QtCreator 2016-10-12T11:39:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConsoleApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    nicandriver.cpp

HEADERS  += mainwindow.h \
    nican.h \
    nicandriver.h

FORMS    += mainwindow.ui

win32: LIBS += -L$$PWD/./ -lnicanmsc

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
