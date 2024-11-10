#include "register_allocator.h"
#include <iostream>

int main() {
    std::vector<std::string> instructions = {
        "a = b + c", "d = a + e", "f = d + g"
    };

    RegisterAllocator allocator;
    allocator.allocateRegisters(instructions);

    allocator.printRegisterAssignments();
    return 0;
}
