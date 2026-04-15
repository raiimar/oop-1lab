#include "menu.h"

#include "exceptions.h"

#include <iostream>
#include <map>
#include <string>

Menu::Menu(ShapeManager& command, Input& input, Output& output, ShapeAdder& shapeAdder)
    : command(command), input(input), output(output), shapeAdder(shapeAdder) {
}

void Menu::handlePrintShapes() {
    output.printShapes(command.getShapes());
}

void Menu::handlePrintShapesWithPerimeter() {
    output.printShapesWithPerimeter(command.getShapes());
}

void Menu::handlePrintTotalPerimeter() {
    output.printTotalPerimeter(command.getTotalPerimeter());
}

void Menu::handleSortPerimeters() {
    command.sortByPerimeter();
    output.printMessage("По чину стало");
}

void Menu::handleRemoveByIndex() {
    output.printMessage("Впиши номеръ:");
    int index = 0;
    if (!input.readInt(index)) {
        output.printMessage("Внемли: Подобаетъ число");
        return;
    }
    command.removeShapeByIndex(static_cast<size_t>(index));
    output.printMessage("Изъято");
}

void Menu::handleRemoveByPerimeter() {
    output.printMessage("Укажи значенїе:");
    double value = 0.0;
    if (!input.readDouble(value)) {
        output.printMessage("Внемли: Подобаетъ число");
        return;
    }
    command.removeShapesWithPerimeterGreaterThan(value);
    output.printMessage("Изъято");
}

void Menu::handleAddShape() {
    shapeAdder.addShape();
}

void Menu::run() {
    static const int exitChoice = 0;
    static const std::map<int, void (Menu::*)()> actionHandlers = {
        {1, &Menu::handleAddShape},
        {2, &Menu::handlePrintShapes},
        {3, &Menu::handlePrintShapesWithPerimeter},
        {4, &Menu::handlePrintTotalPerimeter},
        {5, &Menu::handleSortPerimeters},
        {6, &Menu::handleRemoveByIndex},
        {7, &Menu::handleRemoveByPerimeter}
    };

    bool running = true;
    while (running) {
        output.printMenu();

        int choice = -1;
        if (!input.readInt(choice)) {
            if (std::cin.eof()) {
                running = false;
            }
            else {
                output.printMessage("Внемли: Подобаетъ число");
            }
            continue;
        }

        if (choice == exitChoice) {
            running = false;
            continue;
        }

        std::map<int, void (Menu::*)()>::const_iterator it = actionHandlers.find(choice);
        if (it == actionHandlers.end()) {
            output.printMessage("Внемли: Дѣйство от 0 до 7.");
            continue;
        }

        try {
            (this->*(it->second))();
        } catch (const ShapeException& e) {
            output.printMessage(std::string("Лжа: ") + e.what());
        }
    }
}
