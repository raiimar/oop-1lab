#include "shape_factory.h"

std::shared_ptr<Shape> ShapeFactory::createCircle(const std::string& name, const Point& center, double radius) const {
    return std::make_shared<Circle>(name, center, radius);
}

std::shared_ptr<Shape> ShapeFactory::createRectangle(const std::string& name, const Point& topLeft, const Point& bottomRight) const {
    return std::make_shared<Rectangle>(name, topLeft, bottomRight);
}

std::shared_ptr<Shape> ShapeFactory::createTriangle(const std::string& name, const Point& a, const Point& b, const Point& c) const {
    return std::make_shared<Triangle>(name, a, b, c);
}
