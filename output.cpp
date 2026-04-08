#include "output.h"

#include <iostream>

void Output::printMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add shape\n";
    std::cout << "2. Show shapes\n";
    std::cout << "3. Show shapes with perimeters\n";
    std::cout << "4. Show total perimeter\n";
    std::cout << "5. Sort by perimeter\n";
    std::cout << "6. Remove shape by index\n";
    std::cout << "7. Remove shapes with perimeter greater than value\n";
    std::cout << "0. Exit\n";
}

void Output::printMessage(const std::string& message)
{
    std::cout << message << std::endl;
}

void Output::printError(const std::string& message)
{
    std::cout << "Error: " << message << std::endl;
}

void Output::printShapes(const std::vector<std::shared_ptr<Shape>>& shapes)
{
    size_t index = 0;

    for (const auto& shape : shapes) {
        std::cout << index << ". " << shape->toString() << std::endl;
        index++;
    }
}

void Output::printShapesWithPerimeter(const std::vector<std::shared_ptr<Shape>>& shapes)
{
    size_t index = 0;

    for (const auto& shape : shapes) {
        std::cout << index << ". "
                  << shape->toString()
                  << ", perimeter=" << shape->getPerimeter()
                  << std::endl;
        index++;
    }
}

void Output::printTotalPerimeter(double value)
{
    std::cout << "Total perimeter: " << value << std::endl;
}
