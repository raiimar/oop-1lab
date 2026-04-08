#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "point.h"
#include <string>

class Rectangle : public Shape {
private:
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(const std::string& name, const Point& topLeft, const Point& bottomRight);

    double getPerimeter() const override;
    std::string toString() const override;
};

#endif
