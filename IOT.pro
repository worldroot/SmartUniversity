#-------------------------------------------------
#
# Project created by QtCreator 2018-10-21T20:16:21
#
#-------------------------------------------------

QT       += core gui
QT+= sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IOT
TEMPLATE = app

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
    add_restaurant.cpp \
    add_students.cpp \
    add_types_subscriptions.cpp \
    formulaire_ajout_menu.cpp \
    restaurant.cpp \
    menu.cpp \
    abonne_restaurant.cpp \
    connexion.cpp \
    formulaire_supprimer_menu.cpp

HEADERS += \
        mainwindow.h \
    add_restaurant.h \
    add_students.h \
    add_types_subscriptions.h \
    formulaire_ajout_menu.h \
    restaurant.h \
    menu.h \
    abonne_restaurant.h \
    connexion.h \
    formulaire_supprimer_menu.h

FORMS += \
        mainwindow.ui \
    add_restaurant.ui \
    add_students.ui \
    add_types_subscriptions.ui \
    formulaire_ajout_menu.ui \
    formulaire_supprimer_menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../block brains/network.jpg \
    stylesheet.qss

RESOURCES += \
    images.qrc
