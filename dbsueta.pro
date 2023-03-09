QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_person_command.cpp \
    connector.cpp \
    delete_person_command.cpp \
    main.cpp \
    mainwindow.cpp \
    people_model.cpp \
    update_people_model_command.cpp

HEADERS += \
    add_person_command.hpp \
    connector.hpp \
    delete_person_command.hpp \
    i_command.hpp \
    i_model.hpp \
    i_receiver.hpp \
    mainwindow.h \
    people_model.hpp \
    update_people_model_command.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
