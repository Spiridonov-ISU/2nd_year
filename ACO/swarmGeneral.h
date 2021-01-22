#pragma once
#include "swarm.h" 

class SwarmGeneral : private Swarm {
private:
	vector<vector<char>> matrix;
public:
	SwarmGeneral(char* fileMatrix, Swarm& coords);
	void printMatrix();
	int getMatrixSize();
};