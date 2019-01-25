#-------------------------------------------------
#
# Project created by QtCreator 2019-01-12T23:08:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CarWorkshopManagement
TEMPLATE = app
RC_FILE = ./resources/cwm.rc

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    addservice.cpp \
    delservice.cpp \
    printservice.cpp \
    searchservice.cpp \
    addserviceregularcustomer.cpp \
    addserviceaddedcar.cpp \
    system/sqlite3.c \
    cartoreceivenotification.cpp \
    system/client_management.cpp \
    system/notification.cpp \
    system/menu.cpp

HEADERS += \
    mainwindow.h \
    addservice.h \
    delservice.h \
    printservice.h \
    searchservice.h \
    addserviceregularcustomer.h \
    addserviceaddedcar.h \
    system/client_management.hpp \
    system/menu.hpp \
    system/notification.hpp \
    system/sqlite3.h \
    cartoreceivenotification.h

FORMS += \
        mainwindow.ui \
    addservice.ui \
    delservice.ui \
    printservice.ui \
    searchservice.ui \
    addserviceregularcustomer.ui \
    addserviceaddedcar.ui \
    cartoreceivenotification.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/background.png \
    resources/car.ico \
    resources/cwm.rc
