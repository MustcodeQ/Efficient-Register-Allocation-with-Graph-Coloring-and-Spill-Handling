#include "utils.h"
#include <sstream>

std::vector<std::string> Utils::parseInstruction(const std::string& instruction) {
    std::istringstream stream(instruction);
    std::string token;
    std::vector<std::string> tokens;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}
