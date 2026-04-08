#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

// Базовое исключение для всех ошибок фигур
class ShapeException : public std::exception {
protected:
    std::string message;

public:
    explicit ShapeException(const std::string& msg)
        : message(msg)
    {
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Неверные параметры фигуры
class InvalidFigureException : public ShapeException {
public:
    explicit InvalidFigureException(const std::string& msg)
        : ShapeException(msg)
    {
    }
};

// Вырожденная фигура (например, точки на одной линии)
class DegenerateFigureException : public ShapeException {
public:
    explicit DegenerateFigureException(const std::string& msg)
        : ShapeException(msg)
    {
    }
};

#endif

