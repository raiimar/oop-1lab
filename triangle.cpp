#include "triangle.h"
#include "exceptions.h"

#include <format>
#include <cmath>

#define eps 1e-9
#define half 0.5

static double distance(const Point& p1, const Point& p2)
{
    double dx = p1.getX() - p2.getX();
    double dy = p1.getY() - p2.getY();

    double result = std::sqrt(dx * dx + dy * dy);
    return result;
}

static double area(const Point& a, const Point& b, const Point& c)
{    return half * std::abs(
               a.getX() * (b.getY() - c.getY()) +
               b.getX() * (c.getY() - a.getY()) +
               c.getX() * (a.getY() - b.getY())
               );;
}

Triangle::Triangle(const std::string& name,
                   const Point& a,
                   const Point& b,
                   const Point& c)
    : Shape(name), a(a), b(b), c(c)
{
    if (area(a, b, c) < eps) {
        throw DegenerateFigureException("Triangle is degenerate");
    }
}

double Triangle::getPerimeter() const
{
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ca = distance(c, a);

    double result = ab + bc + ca;
    return result;
}

std::string Triangle::toString() const
{
    return std::format(
        "Triangle: name={}, A=({}, {}), B=({}, {}), C=({}, {})",
        name,
        a.getX(),
        a.getY(),
        b.getX(),
        b.getY(),
        c.getX(),
        c.getY()
        );
}
