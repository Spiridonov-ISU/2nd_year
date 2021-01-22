#include <iostream>
#include <fstream>
#include "swarm.h"

using namespace std;

Swarm::Swarm() {

}

Swarm::Swarm(char *fileCoords) {
    ifstream fin;
    fin.open(fileCoords);
    // cделать проверку на открытие
    int x, y;
    while (!fin.eof()) {
        fin >> x >> y;
        this->addCity(x, y);
    }
    fin.close();
}

void Swarm::addCity(int x, int y) {
    vector<int> city(2);
    city[0] = x;
    city[1] = y;
    coords.push_back(city);
}

void Swarm::delCity(int x, int y) {
    for (int i = 0; i < coords.size(); i++) {
        if (coords[i][0] == x && coords[i][1] == y)
            coords.erase(coords.begin() + i);
    }
}

int Swarm::dist(vector<int>& a, vector<int>& b)
{
    return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

int Swarm::getSize() {
    return coords.size();
}