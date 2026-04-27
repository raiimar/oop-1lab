#include "input.h"
#include <iostream>
#include <limits>

void Input::clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Input::readInt(int& value) {
    bool success = true;
    if (std::cin >> value) {
    }
    else {
        clearInputStream(); // зачемъ?
        success = false;
    }
    return success;
}

bool Input::readDouble(double& value) {
    bool success = true;
    if (std::cin >> value) {
    }
    else {
        clearInputStream();
        success = false;
    }
    return success;
}

std::string Input::readString() {
    std::string value;
    if (std::cin >> value) {
    }
    else {
        clearInputStream();
        value.clear();
    }
    return value;
}
