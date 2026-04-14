#include "commands.h"

#include <algorithm>

void Commands::addShape(const std::shared_ptr<Shape>& shape) {
    shapes.push_back(shape);
}

const std::vector<std::shared_ptr<Shape>>& Commands::getShapes() const {
    return shapes;
}

double Commands::getTotalPerimeter() const {
    double sum = 0.0;

    for (const std::shared_ptr<Shape>& shape : shapes) {
        sum += shape->getPerimeter();
    }

    return sum;
}

bool Commands::comparePerimeter(const std::shared_ptr<Shape>& a, const std::shared_ptr<Shape>& b) {
    return a->getPerimeter() < b->getPerimeter();
}

void Commands::sortByPerimeter() {
    std::sort(shapes.begin(), shapes.end(), comparePerimeter); //с лямбдой
}

void Commands::removeShapeByIndex(size_t index) {
    if (index < shapes.size())
        shapes.erase(shapes.begin() + index);
}

void Commands::removeShapesWithPerimeterGreaterThan(double value) { //без лямбды
    shapes.erase(std::remove_if(shapes.begin(), shapes.end(), [value](const std::shared_ptr<Shape>& shape){return shape->getPerimeter() > value;}), shapes.end());
}
