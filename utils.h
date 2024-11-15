#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

class Utils {
public:
    static std::vector<std::string> parseInstruction(const std::string& instruction);
};

#endif // UTILS_H
