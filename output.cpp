#include "output.h"

#include <iostream>
#include <windows.h>


void Output::printMenu() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────┐\n";
    std::cout << "│ И З Б О Р Ъ                                              │\n";
    std::cout << "├──────────────────────────────────────────────────────────┤\n";
    std::cout << "│ 1. Приложити образъ                                      │\n";
    std::cout << "│ 2. Явити образы                                          │\n";
    std::cout << "│ 3. Явити образы съ периметры ихъ                         │\n";
    std::cout << "│ 4. Явити общую периметру                                 │\n";
    std::cout << "│ 5. Упорядочити по периметре                              │\n";
    std::cout << "│ 6. Отвергнути образъ по указанию                         │\n";
    std::cout << "│ 7. Отвергнути образы, иже периметра боле значенія        │\n";
    std::cout << "│ 0. Изыти (выйти)                                         │\n";
    std::cout << "└──────────────────────────────────────────────────────────┘\n";
    std::cout << "Изволите выбрать действо: ";
}

void Output::printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void Output::printShapes(const std::vector<std::shared_ptr<Shape>>& shapes) {
    size_t index = 0;

    for (const auto& shape : shapes) {
        std::cout << index << ". " << shape->toString() << std::endl;
        index++;
    }
}

void Output::printShapesWithPerimeter(const std::vector<std::shared_ptr<Shape>>& shapes) {
    size_t index = 0;

    for (const auto& shape : shapes) {
        std::cout << index << ". " << shape->toString() << ", периметра=" << shape->getPerimeter() << std::endl;
        index++;
    }
}

void Output::printTotalPerimeter(double value) {
    std::cout << "Общая периметра: " << value << std::endl;
}
