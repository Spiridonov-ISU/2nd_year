#pragma once

#include "swarmGeneral.h"
#include <vector>

using namespace std;

class ACO {
private:
    int currentNode;
    vector<int> unvisitedNodes;
    vector<int> visitedNodes;
    void selectNode(SwarmGeneral& matrix, int alpha, int beta);
    void addPheromone(SwarmGeneral& matrix, double evaporation);

public:
    ACO(vector<int> unvisitedNodes);
    void search(SwarmGeneral& matrix, int alpha, int beta, double evaporation);
};