#ifndef INPUT_H
#define INPUT_H

#include <string>

class Input { //
public:
    static bool readInt(int& value);
    static bool readDouble(double& value);
    static std::string readString();
};

#endif
