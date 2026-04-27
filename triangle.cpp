#include "triangle.h"
#include "exceptions.h"

#include <format>
#include <cmath>

#define eps 1e-9
#define half 0.5

static double distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;

    return std::sqrt(dx * dx + dy * dy);;
}

static double area(const Point& a, const Point& b, const Point& c) {
    return half * std::abs(a.x * (b.x - c.x) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

Triangle::Triangle(const std::string& name, const Point& a, const Point& b, const Point& c) : Shape(name), a(a), b(b), c(c) {
    if (area(a, b, c) < eps)
        throw DegenerateFigureException("Треугольникъ вырожденъ");
}

double Triangle::getPerimeter() const {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ca = distance(c, a);

    return ab + bc + ca;
}

std::string Triangle::toString() const {
    return std::format(
        "Треугольникъ: имѧ={}, Азъ=({}, {}), Буки=({}, {}), Веди=({}, {})",
        name,
        a.x,
        a.y,
        b.x,
        b.y,
        c.x,
        c.y
        );
}
