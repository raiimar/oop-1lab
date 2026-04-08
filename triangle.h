#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "point.h"
#include <string>

class Triangle : public Shape {
private:
    Point a;
    Point b;
    Point c;

public:
    Triangle(const std::string& name, const Point& a, const Point& b, const Point& c);

    double getPerimeter() const override;
    std::string toString() const override;
};

#endif
