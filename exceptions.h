#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class ShapeException : public std::exception {
protected:
    std::string message;

public:
    ShapeException(const std::string& msg);
    const char* what() const noexcept override;
};

// неверные параметры фигуры тип радиус меньше 0
class InvalidFigureException : public ShapeException {
public:
    InvalidFigureException(const std::string& msg);
};

// вырожденная фигура
class DegenerateFigureException : public ShapeException {
public:
    DegenerateFigureException(const std::string& msg);
};

#endif
