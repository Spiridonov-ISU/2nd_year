#pragma once
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> v;
    int edges = 0;
    int nodes = 0;
    void addWay(int a, int b);
public:
    Graph(char* fileName);
    int connectivityComponent();
};