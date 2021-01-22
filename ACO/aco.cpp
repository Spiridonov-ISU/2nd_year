#include "aco.h"

ACO::ACO(vector<int> unvisitedNodes) : unvisitedNodes(unvisitedNodes) {
    currentNode = 0;
    visitedNodes.push_back(0);
}