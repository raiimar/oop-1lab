#include "menu.h"

#include "input.h"
#include "output.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "point.h"
#include "exceptions.h"

#include <iostream>
#include <memory>
#include <string>

int Menu::getUserChoice() { //
    Output::printMenu();
    int result = -1;
    int choice = -1;
    if (!Input::readInt(choice)) {
        if (std::cin.eof()) {
            result = EXIT_MENU;
        }
        else {
            Output::printMessage("Внемли: Подобаетъ число");
        }
    }
    else if (choice < EXIT_MENU || choice > REMOVE_BY_PERIMETR) {
        Output::printMessage("Внемли: Дѣйство от 0 до 7.");
    }
    else {
        result = choice;
    }
    return result;
}

void Menu::processChoice(int choice) { //
    if (choice == ADD_SHAPE) {
        handleAddShape();
    }
    else if (choice == PRINT_SHAPES) {
        Output::printShapes(command.getShapes());
    }
    else if (choice == PRINT_SHAPES_WITH_PERIMETR) {
        Output::printShapesWithPerimeter(command.getShapes());
    }
    else if (choice == PRINT_TOTAL_PERIMETR) {
        Output::printTotalPerimeter(command.getTotalPerimeter());
    }
    else if (choice == SORT_PERIMETRS) {
        command.sortByPerimeter();
        Output::printMessage("По чину стало");
    }
    else if (choice == REMOVE_BY_INDEX) {
        handleRemoveByIndex();
    }
    else if (choice == REMOVE_BY_PERIMETR) {
        handleRemoveByPerimeter();
    }
}

void Menu::handleRemoveByIndex() {
    Output::printMessage("Впиши номеръ:");
    int index = 0;
    if (!Input::readInt(index)) {
        Output::printMessage("Внемли: Подобаетъ число");
        return;
    }
    command.removeShapeByIndex(static_cast<size_t>(index));
    Output::printMessage("Изъято");
}

void Menu::handleRemoveByPerimeter() {
    Output::printMessage("Укажи значенїе:");
    double value = 0.0;
    if (!Input::readDouble(value)) {
        Output::printMessage("Внемли: Подобаетъ число");
        return;
    }
    command.removeShapesWithPerimeterGreaterThan(value);
    Output::printMessage("Изъято");
}

void Menu::handleAddCircle(const std::string& name) {
    double x = 0.0, y = 0.0, r = 0.0;
    Output::printMessage("Впиши центръ (х у):");
    if (!Input::readDouble(x) || !Input::readDouble(y)) {
        Output::printMessage("Внемли: Подобаетъ число");
    }
    else {
        Output::printMessage("Впиши радіусъ:");
        if (!Input::readDouble(r)) {
            Output::printMessage("Внемли: Подобаетъ число");
        }
        else {
            auto shape = std::make_shared<Circle>(name, Point(x, y), r);
            command.addShape(shape);
        }
    }
    return;
}

void Menu::handleAddRectangle(const std::string& name) {
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
    Output::printMessage("Впиши верхнѧ́ѧ лѣ́ваѧ точка(х у):");
    if (!Input::readDouble(x1) || !Input::readDouble(y1)) {
        Output::printMessage("Внемли: Подобаетъ число");
    }
    else {
        Output::printMessage("Впиши ни́жнѧѧ пра́ваѧ точка(х у):");
        if (!Input::readDouble(x2) || !Input::readDouble(y2)) {
            Output::printMessage("Внемли: Подобаетъ число");
        }
        else {
            auto shape = std::make_shared<Rectangle>(name, Point(x1, y1), Point(x2, y2));
            command.addShape(shape);
        }
    }
    return;
}

void Menu::handleAddTriangle(const std::string& name) {
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
    Output::printMessage("Впиши точку Азъ (х у):");
    if (!Input::readDouble(x1) || !Input::readDouble(y1)) {
        Output::printMessage("Внемли: Подобаетъ число");
    }
    else {
        Output::printMessage("Впиши точку Буки (х у):");
        if (!Input::readDouble(x2) || !Input::readDouble(y2)) {
            Output::printMessage("Внемли: Подобаетъ число");
        }
        else {
            Output::printMessage("Впиши точку Веди (х у):");
            if (!Input::readDouble(x3) || !Input::readDouble(y3)) {
                Output::printMessage("Внемли: Подобаетъ число");
            }
            else {
                auto shape = std::make_shared<Triangle>(name, Point(x1, y1), Point(x2, y2), Point(x3, y3));
                command.addShape(shape);
            }
        }
    }
    return;
}

void Menu::handleAddShape() {
    Output::printMessage("Избери образъ: 1-Кругъ, 2-Прямоугольникъ, 3-Треугольникъ");

    int type = 0;
    if (!Input::readInt(type) || type > TRIANGLE || type < CIRCLE ) {
        Output::printMessage("Внемли: Подобаетъ число 1, 2 иль 3");
        return;
    }

    Output::printMessage("Впиши имѧ:");
    std::string name = Input::readString();

    if (type == 1) {
        handleAddCircle(name);
    }
    else if (type == 2) {
        handleAddRectangle(name);
    }
    else if (type == 3) {
        handleAddTriangle(name);
    }
}

void Menu::run() {
    int choice = 0;
    bool running = 1;
    while (running) {
        choice = getUserChoice();
        if (choice == EXIT_MENU) {
            running = 0;
        }
        else if (choice != -1) {
            try {
                processChoice(choice);
            } catch (const ShapeException& e) {
                Output::printMessage(std::string("Лжа: ") + e.what());
            }
        }
    }
}
