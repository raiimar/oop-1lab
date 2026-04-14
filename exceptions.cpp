#include "exceptions.h"

ShapeException::ShapeException(const std::string& msg) : message(msg) {
}

const char* ShapeException::what() const noexcept {
    return message.c_str();
}

InvalidFigureException::InvalidFigureException(const std::string& msg) : ShapeException(msg) {
}

DegenerateFigureException::DegenerateFigureException(const std::string& msg) : ShapeException(msg) {
}
