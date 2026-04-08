#ifndef COMMANDS_H
#define COMMANDS_H

#include "shape.h"
#include <vector>
#include <memory>

class Commands {
private:
    std::vector<std::shared_ptr<Shape>> shapes;

public:
    Commands() = default;

    void addShape(const std::shared_ptr<Shape>& shape);

    const std::vector<std::shared_ptr<Shape>>& getShapes() const;

    double getTotalPerimeter() const;

    void sortByPerimeter();

    void removeShapeByIndex(size_t index);

    void removeShapesWithPerimeterGreaterThan(double value);
};

#endif
