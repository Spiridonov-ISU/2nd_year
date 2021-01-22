#pragma once
#include <vector>

using namespace std;

class Swarm {
private:
    vector<vector <int>> coords;
public:
    Swarm();
    Swarm(char* fileCoords);
    void addCity(int x, int y);
    void delCity(int x, int y);
    int dist(vector<int>& a, vector<int>& b);
    int getSize();
};