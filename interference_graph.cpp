#include "interference_graph.h"
#include <iostream>

void InterferenceGraph::buildGraph(const std::vector<std::string>& instructions) {
    // Basic example, build an interference graph (parse instructions)
    adjList["a"].insert("b");
    adjList["a"].insert("c");
    adjList["d"].insert("a");
    adjList["f"].insert("d");
    // Add edges as necessary based on variable lifetimes.
}

int InterferenceGraph::getDegree(const std::string& node) const {
    return adjList.at(node).size();
}

int InterferenceGraph::colorNode(const std::string& node, int numRegisters) {
    std::unordered_set<int> availableColors;
    for (int i = 0; i < numRegisters; ++i) {
        availableColors.insert(i);
    }

    for (const auto& neighbor : adjList[node]) {
        if (nodeColors.find(neighbor) != nodeColors.end()) {
            availableColors.erase(nodeColors[neighbor]);
        }
    }

    int color = *availableColors.begin();
    nodeColors[node] = color;
    return color;
}

const std::unordered_set<std::string>& InterferenceGraph::getNodes() const {
    static std::unordered_set<std::string> nodes;
    for (const auto& [key, _] : adjList) {
        nodes.insert(key);
    }
    return nodes;
}
