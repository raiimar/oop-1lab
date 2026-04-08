TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        circle.cpp \
        commands.cpp \
        exceptions.cpp \
        input.cpp \
        main.cpp \
        menu.cpp \
        output.cpp \
        point.cpp \
        rectangle.cpp \
        shape.cpp \
        triangle.cpp

HEADERS += \
    circle.h \
    commands.h \
    exceptions.h \
    input.h \
    menu.h \
    output.h \
    point.h \
    rectangle.h \
    shape.h \
    triangle.h
