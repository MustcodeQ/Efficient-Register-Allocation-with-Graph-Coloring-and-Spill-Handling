#include "spill_code.h"
#include <iostream>

void SpillCode::handleSpill(const std::string& variable) {
    std::cout << "Spilling variable: " << variable << " to memory." << std::endl;
}
