#include <iostream>
#include <fstream>
#include "swarm.h"
#include "swarmGeneral.h"

SwarmGeneral::SwarmGeneral(char* fileMatrix, Swarm &coords):Swarm() {
    
    ifstream fin;
    fin.open(fileMatrix);
    // cделать проверку на открытие
    int sizeMatrix = coords.getSize();
    char ch;
    for (int i = 0; i < sizeMatrix; i++) {
        vector<char> row(sizeMatrix);
        for (int j = 0; j < sizeMatrix; j++) {
            fin >> ch;
            row[j] = ch;
        }
        matrix.push_back(row);
    }
    fin.close();
}

void SwarmGeneral::printMatrix() {
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int SwarmGeneral::getMatrixSize() {
    return matrix.size();
}