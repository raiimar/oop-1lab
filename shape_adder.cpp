#include "shape_adder.h"

#include "point.h"

ShapeAdder::ShapeAdder(ShapeManager& shapeManager, ShapeFactory& shapeFactory, Input& input, Output& output)
    : shapeManager(shapeManager), shapeFactory(shapeFactory), input(input), output(output) {
}

void ShapeAdder::addCircle(const std::string& name) {
    double x = 0.0;
    double y = 0.0;
    double r = 0.0;
    output.printMessage("Впиши центръ (х у):");
    if (!input.readDouble(x) || !input.readDouble(y)) {
        output.printMessage("Внемли: Подобаетъ число");
    }
    else {
        output.printMessage("Впиши радіусъ:");
        if (!input.readDouble(r)) {
            output.printMessage("Внемли: Подобаетъ число");
        }
        else {
            std::shared_ptr<Shape> shape = shapeFactory.createCircle(name, Point{x, y}, r);
            shapeManager.addShape(shape);
        }
    }
}

void ShapeAdder::addRectangle(const std::string& name) {
    double x1 = 0.0;
    double y1 = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    output.printMessage("Впиши верхнѧ́ѧ лѣ́ваѧ точка(х у):");
    if (!input.readDouble(x1) || !input.readDouble(y1)) {
        output.printMessage("Внемли: Подобаетъ число");
    }
    else {
        output.printMessage("Впиши ни́жнѧѧ пра́ваѧ точка(х у):");
        if (!input.readDouble(x2) || !input.readDouble(y2)) {
            output.printMessage("Внемли: Подобаетъ число");
        }
        else {
            std::shared_ptr<Shape> shape = shapeFactory.createRectangle(name, Point{x1, y1}, Point{x2, y2});
            shapeManager.addShape(shape);
        }
    }
}

void ShapeAdder::addTriangle(const std::string& name) {
    double x1 = 0.0;
    double y1 = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    double x3 = 0.0;
    double y3 = 0.0;
    output.printMessage("Впиши точку Азъ (х у):");
    if (!input.readDouble(x1) || !input.readDouble(y1)) {
        output.printMessage("Внемли: Подобаетъ число");
    }
    else {
        output.printMessage("Впиши точку Буки (х у):");
        if (!input.readDouble(x2) || !input.readDouble(y2)) {
            output.printMessage("Внемли: Подобаетъ число");
        }
        else {
            output.printMessage("Впиши точку Веди (х у):");
            if (!input.readDouble(x3) || !input.readDouble(y3)) {
                output.printMessage("Внемли: Подобаетъ число");
            }
            else {
                std::shared_ptr<Shape> shape = shapeFactory.createTriangle(name, Point{x1, y1}, Point{x2, y2}, Point{x3, y3});
                shapeManager.addShape(shape);
            }
        }
    }
}

void ShapeAdder::addShape() {
    output.printMessage("Избери образъ: 1-Кругъ, 2-Прямоугольникъ, 3-Треугольникъ");

    int type = 0;
    bool isTypeValid = (
        input.readInt(type) &&
        type <= static_cast<int>(ShapeType::Triangle) &&
        type >= static_cast<int>(ShapeType::Circle)
    );

    if (!isTypeValid) {
        output.printMessage("Внемли: Подобаетъ число 1, 2 иль 3");
    }
    else {
        output.printMessage("Впиши имѧ:");
        std::string name = input.readString();
        ShapeType shapeType = static_cast<ShapeType>(type);

        if (shapeType == ShapeType::Circle) {
            addCircle(name);
        }
        else if (shapeType == ShapeType::Rectangle) {
            addRectangle(name);
        }
        else if (shapeType == ShapeType::Triangle) {
            addTriangle(name);
        }
    }
}
