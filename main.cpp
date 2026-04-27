#include "menu.h"
#include "shape_manager.h"
#include "input.h"
#include "output.h"
#include "shape_adder.h"
#include "shape_factory.h"

int main() {
    ShapeManager shapeManager;
    ShapeFactory shapeFactory;
    Input input;
    Output output;
    ShapeAdder shapeAdder(shapeManager, shapeFactory, input, output);
    Menu menu(shapeManager, input, output, shapeAdder);
    menu.run();
    return 0;
}
