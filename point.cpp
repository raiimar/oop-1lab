#include "Point.h"

// Конструктор по умолчанию
Point::Point() {
    x = 0.0;
    y = 0.0;
}

// Конструктор с параметрами
Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

// getters
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

// setters
void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}
