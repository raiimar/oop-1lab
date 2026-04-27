#include "circle.h"
#include "exceptions.h"

#include <format>
#define double_pi 6.283184

Circle::Circle(const std::string& name, const Point& center, double radius) : Shape(name), center(center), radius(radius) {
    if (radius <= 0)
        throw InvalidFigureException("Радіусъ подобаетъ быти положительну");
}

double Circle::getPerimeter() const {
    return double_pi * radius;
}

std::string Circle::toString() const {
    return std::format( "Кругъ: имѧ={}, центръ=({}, {}), радіусъ={}",
        name,
        center.x,
        center.y,
        radius
    );
}
