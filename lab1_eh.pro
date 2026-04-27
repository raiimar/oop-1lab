TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        circle.cpp \
        exceptions.cpp \
        input.cpp \
        main.cpp \
        menu.cpp \
        output.cpp \
        point.cpp \
        rectangle.cpp \
        shape_factory.cpp \
        shape_adder.cpp \
        shape_manager.cpp \
        shape.cpp \
        triangle.cpp

HEADERS += \
    circle.h \
    exceptions.h \
    input.h \
    menu.h \
    output.h \
    point.h \
    rectangle.h \
    shape_factory.h \
    shape_adder.h \
    shape_manager.h \
    shape.h \
    triangle.h
