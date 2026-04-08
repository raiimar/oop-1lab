#include "circle.h"
#include "exceptions.h"

#include <algorithm>
#include <format>
#define pi 3.141592653589793

Circle::Circle(const std::string& name, const Point& center, double radius) : Shape(name), center(center), radius(radius)
{
    if (radius <= 0) {
        throw InvalidFigureException("Radius must be positive");
    }
}

double Circle::getPerimeter() const
{
    return 2 * pi * radius;
}

std::string Circle::toString() const
{
    std::string result = std::format(
        "Circle: name={}, center=({}, {}), radius={}",
        name,
        center.getX(),
        center.getY(),
        radius
        );
    return result;
}
