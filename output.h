#ifndef OUTPUT_H
#define OUTPUT_H

#include "shape.h"
#include <vector>
#include <memory>
#include <string>

class Output {
public:
    static void printMenu();
    static void printMessage(const std::string& message);
    static void printError(const std::string& message);
    static void printShapes(const std::vector<std::shared_ptr<Shape>>& shapes);
    static void printShapesWithPerimeter(const std::vector<std::shared_ptr<Shape>>& shapes);
    static void printTotalPerimeter(double value);
};

#endif
