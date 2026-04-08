#include "input.h"

#include <iostream>

int Input::readInt()
{
    int value = 0;
    std::cin >> value;
    return value;
}

double Input::readDouble()
{
    double value = 0.0;
    std::cin >> value;
    return value;
}

std::string Input::readString()
{
    std::string value;
    std::cin >> value;
    return value;
}
