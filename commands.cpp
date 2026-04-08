#include "commands.h"

#include <algorithm>

void Commands::addShape(const std::shared_ptr<Shape>& shape)
{
    shapes.push_back(shape);
}

const std::vector<std::shared_ptr<Shape>>& Commands::getShapes() const
{
    const std::vector<std::shared_ptr<Shape>>& result = shapes;
    return result;
}

double Commands::getTotalPerimeter() const
{
    double sum = 0.0;

    for (const auto& shape : shapes) {
        sum += shape->getPerimeter();
    }

    double result = sum;
    return result;
}

void Commands::sortByPerimeter()
{
    std::sort(shapes.begin(), shapes.end(),
              [](const std::shared_ptr<Shape>& a,
                 const std::shared_ptr<Shape>& b)
              {
                  bool result = a->getPerimeter() < b->getPerimeter();
                  return result;
              });
}

void Commands::removeShapeByIndex(size_t index)
{
    if (index < shapes.size()) {
        shapes.erase(shapes.begin() + index);
    }
}

void Commands::removeShapesWithPerimeterGreaterThan(double value)
{
    shapes.erase(
        std::remove_if(shapes.begin(), shapes.end(),
                       [value](const std::shared_ptr<Shape>& shape)
                       {
                           bool result = shape->getPerimeter() > value;
                           return result;
                       }),
        shapes.end()
        );
}
