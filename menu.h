#ifndef MENU_H
#define MENU_H

#include "commands.h"

class Menu {
private:
    Commands command;

    void handleAddShape();

public:
    void run();
};

#endif
