#include "rectangle.h"
#include "exceptions.h"

#include <format>
#include <cmath>

Rectangle::Rectangle(const std::string& name, const Point& topLeft, const Point& bottomRight) : Shape(name), topLeft(topLeft), bottomRight(bottomRight) {
    if (topLeft.x == bottomRight.x || topLeft.y == bottomRight.y)
        throw DegenerateFigureException("Прямоугольникъ вырожденъ");
}

double Rectangle::getPerimeter() const {
    double width = std::abs(bottomRight.x - topLeft.x);
    double height = std::abs(topLeft.y - bottomRight.y);

    return 2 * (width + height);
}

std::string Rectangle::toString() const {
    return std::format( "Прямоугольникъ: имѧ={}, верхнѧѧ лѣваѧ точка=({}, {}), нижнѧѧ праваѧ точка=({}, {})",
        name,
        topLeft.x,
        topLeft.y,
        bottomRight.x,
        bottomRight.y
    );
}
