#ifndef SHAPE_ADDER_H
#define SHAPE_ADDER_H

#include "shape_manager.h"
#include "input.h"
#include "output.h"

#include <string>

class ShapeAdder {
private:
    enum class ShapeType {
        Circle = 1,
        Rectangle = 2,
        Triangle = 3
    };

    ShapeManager& command;
    Input& input;
    Output& output;

    void addCircle(const std::string& name);
    void addRectangle(const std::string& name);
    void addTriangle(const std::string& name);

public:
    ShapeAdder(ShapeManager& command, Input& input, Output& output);
    void addShape();
};

#endif
