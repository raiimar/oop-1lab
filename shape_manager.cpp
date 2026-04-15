#include "shape_manager.h"

#include <algorithm>

void ShapeManager::addShape(const std::shared_ptr<Shape>& shape) {
    shapes.push_back(shape);
}

const std::vector<std::shared_ptr<Shape>>& ShapeManager::getShapes() const {
    return shapes;
}

double ShapeManager::getTotalPerimeter() const {
    double sum = 0.0;

    for (const std::shared_ptr<Shape>& shape : shapes) {
        sum += shape->getPerimeter();
    }

    return sum;
}

void ShapeManager::sortByPerimeter() { //с лямбдой
    std::sort(shapes.begin(), shapes.end(), [](const std::shared_ptr<Shape>& a, const std::shared_ptr<Shape>& b) {
        bool result = a->getPerimeter() < b->getPerimeter();
        return result;
    });
}

void ShapeManager::removeShapeByIndex(size_t index) {
    if (index < shapes.size())
        shapes.erase(shapes.begin() + index);
}

void ShapeManager::removeShapesWithPerimeterGreaterThan(double value) { //без лямбды
    std::vector<std::shared_ptr<Shape>>::iterator it = shapes.begin();
    while (it != shapes.end()) {
        if ((*it)->getPerimeter() > value) {
            it = shapes.erase(it);
        }
        else {
            ++it;
        }
    }
}
