#include "rectangle.h"
#include "exceptions.h"

#include <format>
#include <cmath>

Rectangle::Rectangle(const std::string& name, const Point& topLeft, const Point& bottomRight) : Shape(name), topLeft(topLeft), bottomRight(bottomRight) {
    if (topLeft.getX() == bottomRight.getX() || topLeft.getY() == bottomRight.getY())
        throw DegenerateFigureException("Прямоугольникъ вырожденъ");
}

double Rectangle::getPerimeter() const {
    double width = std::abs(bottomRight.getX() - topLeft.getX());
    double height = std::abs(topLeft.getY() - bottomRight.getY());

    return 2 * (width + height);
}

std::string Rectangle::toString() const {
    return std::format( "Прямоугольникъ: имѧ={}, верхнѧѧ лѣваѧ точка=({}, {}), нижнѧѧ праваѧ точка=({}, {})",
        name,
        topLeft.getX(),
        topLeft.getY(),
        bottomRight.getX(),
        bottomRight.getY()
    );
}
