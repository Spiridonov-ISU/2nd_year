#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

Graph::Graph(char* fileName) {
    this->edges = 0;
    this->nodes = 0;
    ifstream fin(fileName);
    if (fin.is_open()) {
        int a, b;
        while (!fin.eof()) {
            fin >> a >> b;
            addWay(a, b);
            nodes = nodes > a ? nodes : a;
            nodes = nodes > b ? nodes : b;
            edges++;
        }
        nodes++;
        fin.close();
    } else {
        return;
    }
}

void Graph::addWay(int a, int b) {
    vector<int> way(2);
    way[0] = a;
    way[1] = b;
    v.push_back(way);
}

int Graph::connectivityComponent() {
    bool* visit = new bool[nodes] { false };        
    int ans = 0;

    for (int i = 0; i < edges; i++) {
        if (!(visit[v[i][0]] && visit[v[i][1]])) {
            ans += 1;
            visit[v[i][0]] = true;
            visit[v[i][1]] = true;
        }
        else
            ans -= 1;
    }
    delete[] visit;
    return ans;
}