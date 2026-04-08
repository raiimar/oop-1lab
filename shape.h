#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
protected:
    std::string name;

public:
    explicit Shape(const std::string& name);
    virtual ~Shape() = default;

    std::string getName() const;

    virtual double getPerimeter() const = 0;
    virtual std::string toString() const = 0;
};

#endif
