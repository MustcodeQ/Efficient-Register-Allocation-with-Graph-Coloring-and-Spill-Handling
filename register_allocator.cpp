#include "register_allocator.h"
#include "spill_code.h"
#include <iostream>

RegisterAllocator::RegisterAllocator() {}

void RegisterAllocator::allocateRegisters(const std::vector<std::string>& instructions) {
    graph.buildGraph(instructions);

    for (const auto& node : graph.getNodes()) {
        if (graph.getDegree(node) < NUM_REGISTERS) {
            registerAssignments[node] = graph.colorNode(node, NUM_REGISTERS);
        } else {
            SpillCode::handleSpill(node);
        }
    }
}

void RegisterAllocator::printRegisterAssignments() {
    for (const auto& [var, reg] : registerAssignments) {
        std::cout << "Variable " << var << " -> Register " << reg << std::endl;
    }
}
