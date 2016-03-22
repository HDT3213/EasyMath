#-------------------------------------------------
#
# Project created by QtCreator 2015-10-05T20:16:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyMath
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calsolver.cpp \
    numkeyboard.cpp \
    funcgraph.cpp

HEADERS  += mainwindow.h \
    calsolver.h \
    numkeyboard.h \
    funcgraph.h

FORMS    += mainwindow.ui \
    numkeyboard.ui \
    funcgraph.ui
