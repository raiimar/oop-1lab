#include "menu.h"

#include "input.h"
#include "output.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "point.h"
#include "exceptions.h"

#include <memory>

void Menu::run()
{
    int choice = -1;

    while (choice != 0) {
        Output::printMenu();
        choice = Input::readInt();

        try {
            if (choice == 1) {
                handleAddShape();
            }
            else if (choice == 2) {
                Output::printShapes(command.getShapes());
            }
            else if (choice == 3) {
                Output::printShapesWithPerimeter(command.getShapes());
            }
            else if (choice == 4) {
                Output::printTotalPerimeter(command.getTotalPerimeter());
            }
            else if (choice == 5) {
                command.sortByPerimeter();
                Output::printMessage("Sorted");
            }
            else if (choice == 6) {
                Output::printMessage("Enter index:");
                int index = Input::readInt();
                command.removeShapeByIndex(index);
                Output::printMessage("Removed");
            }
            else if (choice == 7) {
                Output::printMessage("Enter value:");
                double value = Input::readDouble();
                command.removeShapesWithPerimeterGreaterThan(value);
                Output::printMessage("Removed");
            }
        }
        catch (const ShapeException& e) {
            Output::printError(e.what());
        }
    }
}

void Menu::handleAddShape()
{
    Output::printMessage("Choose shape: 1-Circle, 2-Rectangle, 3-Triangle");

    int type = Input::readInt();

    Output::printMessage("Enter name:");
    std::string name = Input::readString();

    if (type == 1) {
        Output::printMessage("Enter center (x y):");
        double x = Input::readDouble();
        double y = Input::readDouble();

        Output::printMessage("Enter radius:");
        double r = Input::readDouble();

        auto shape = std::make_shared<Circle>(name, Point(x, y), r);
        command.addShape(shape);
    }
    else if (type == 2) {
        Output::printMessage("Enter top-left (x y):");
        double x1 = Input::readDouble();
        double y1 = Input::readDouble();

        Output::printMessage("Enter bottom-right (x y):");
        double x2 = Input::readDouble();
        double y2 = Input::readDouble();

        auto shape = std::make_shared<Rectangle>(
            name,
            Point(x1, y1),
            Point(x2, y2)
            );

        command.addShape(shape);
    }
    else if (type == 3) {
        Output::printMessage("Enter point A:");
        double x1 = Input::readDouble();
        double y1 = Input::readDouble();

        Output::printMessage("Enter point B:");
        double x2 = Input::readDouble();
        double y2 = Input::readDouble();

        Output::printMessage("Enter point C:");
        double x3 = Input::readDouble();
        double y3 = Input::readDouble();

        auto shape = std::make_shared<Triangle>(
            name,
            Point(x1, y1),
            Point(x2, y2),
            Point(x3, y3)
            );

        command.addShape(shape);
    }
}
