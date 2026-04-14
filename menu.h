#ifndef MENU_H
#define MENU_H

#include "commands.h"

enum { //
    EXIT_MENU,
    ADD_SHAPE,
    PRINT_SHAPES,
    PRINT_SHAPES_WITH_PERIMETR,
    PRINT_TOTAL_PERIMETR,
    SORT_PERIMETRS,
    REMOVE_BY_INDEX,
    REMOVE_BY_PERIMETR
};

enum {
    CIRCLE = 1,
    RECTANGLE = 2,
    TRIANGLE = 3
};

class Menu {
private:
    Commands command;
    int getUserChoice();
    void processChoice(int choice);
    void handleAddCircle(const std::string& name);
    void handleAddRectangle(const std::string& name);
    void handleAddTriangle(const std::string& name);
    void handleAddShape();
    void handleRemoveByIndex();
    void handleRemoveByPerimeter();

public:
    void run();
};

#endif
