#ifndef MENU_H
#define MENU_H

#include "shape_manager.h"
#include "input.h"
#include "output.h"
#include "shape_adder.h"

class Menu {
private:
    ShapeManager& shapeManager;
    Input& input;
    Output& output;
    ShapeAdder& shapeAdder;
    void handleAddShape();
    void handleRemoveByIndex();
    void handleRemoveByPerimeter();
    void handlePrintShapes();
    void handlePrintShapesWithPerimeter();
    void handlePrintTotalPerimeter();
    void handleSortPerimeters();

public:
    Menu(ShapeManager& shapeManager, Input& input, Output& output, ShapeAdder& shapeAdder);
    void run();
};

#endif
