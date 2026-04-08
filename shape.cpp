#include "shape.h"

Shape::Shape(const std::string& name) : name(name)
{
}

std::string Shape::getName() const
{
    std::string result = name;
    return result;
}
