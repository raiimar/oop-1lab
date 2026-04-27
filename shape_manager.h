#ifndef SHAPE_MANAGER_H
#define SHAPE_MANAGER_H

#include "shape.h"

#include <memory>
#include <vector>

class ShapeManager {
private:
    std::vector<std::shared_ptr<Shape>> shapes;

public:
    ShapeManager() = default;

    void addShape(const std::shared_ptr<Shape>& shape);
    const std::vector<std::shared_ptr<Shape>>& getShapes() const;

    double getTotalPerimeter() const;

    void sortByPerimeter();

    void removeShapeByIndex(size_t index);
    void removeShapesWithPerimeterGreaterThan(double value);
};

#endif
