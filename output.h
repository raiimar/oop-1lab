#ifndef OUTPUT_H
#define OUTPUT_H

#include "shape.h"
#include <vector>
#include <memory>
#include <string>

class Output {
public:
    void printMenu();
    void printMessage(const std::string& message);
    void printShapes(const std::vector<std::shared_ptr<Shape>>& shapes);
    void printShapesWithPerimeter(const std::vector<std::shared_ptr<Shape>>& shapes);
    void printTotalPerimeter(double value);
};

#endif
