#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

#include <memory>
#include <string>

class ShapeFactory {
public:
    std::shared_ptr<Shape> createCircle(const std::string& name, const Point& center, double radius) const;
    std::shared_ptr<Shape> createRectangle(const std::string& name, const Point& topLeft, const Point& bottomRight) const;
    std::shared_ptr<Shape> createTriangle(const std::string& name, const Point& a, const Point& b, const Point& c) const;
};

#endif
