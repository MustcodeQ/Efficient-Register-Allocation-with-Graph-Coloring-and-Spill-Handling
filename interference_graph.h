#ifndef INTERFERENCE_GRAPH_H
#define INTERFERENCE_GRAPH_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class InterferenceGraph {
public:
    void buildGraph(const std::vector<std::string>& instructions);
    int getDegree(const std::string& node) const;
    int colorNode(const std::string& node, int numRegisters);
    const std::unordered_set<std::string>& getNodes() const;

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;
    std::unordered_map<std::string, int> nodeColors;
};

#endif // INTERFERENCE_GRAPH_H
