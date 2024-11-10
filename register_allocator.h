#ifndef REGISTER_ALLOCATOR_H
#define REGISTER_ALLOCATOR_H

#include "interference_graph.h"
#include <vector>
#include <string>
#include <unordered_map>

class RegisterAllocator {
public:
    RegisterAllocator();
    void allocateRegisters(const std::vector<std::string>& instructions);
    void printRegisterAssignments();

private:
    InterferenceGraph graph;
    std::unordered_map<std::string, int> registerAssignments;
    const int NUM_REGISTERS = 4;
};

#endif // REGISTER_ALLOCATOR_H
