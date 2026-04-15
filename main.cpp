#include "menu.h"
#include "shape_manager.h"
#include "input.h"
#include "output.h"
#include "shape_adder.h"

int main() {
    ShapeManager command;
    Input input;
    Output output;
    ShapeAdder shapeAdder(command, input, output);
    Menu menu(command, input, output, shapeAdder);
    menu.run();
    return 0;
}
