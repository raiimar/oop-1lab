#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point.h"
#include <string>

class Circle : public Shape {
private:
    Point center;
    double radius;

public:
    Circle(const std::string& name, const Point& center, double radius);

    double getPerimeter() const override;
    std::string toString() const override;
};

#endif
