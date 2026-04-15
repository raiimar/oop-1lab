#ifndef INPUT_H
#define INPUT_H

#include <string>

class Input {
public:
    bool readInt(int& value);
    bool readDouble(double& value);
    std::string readString();
};

#endif
