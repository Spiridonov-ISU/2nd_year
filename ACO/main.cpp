#include <iostream>
#include "swarm.h"
#include "swarmGeneral.h"
#include "aco.h"

using namespace std;

void runACO(int swarmSize, int iterations, int alpha, int beta, double evaporation, SwarmGeneral& matrix) {
    vector<int> nodes;
    for (int i = 1; i < matrix.getMatrixSize(); i++)
        nodes.push_back(i);
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < swarmSize; j++) {
            ACO aco{nodes};
            aco.search(matrix, alpha, beta, evaporation);
        }
    }
}

int main() {
    char pathFileCoords[] = "FileCoords.txt";
    char pathFileMatrix[] = "FileMatrix.txt";
    Swarm coordsCities(pathFileCoords);
    SwarmGeneral matrix(pathFileMatrix, coordsCities);




    return 0;
}
//
//Реализовать алгоритм пчелиного роя. 
//Разработайте класс «Swarm».
//В классе реализовать конструктор, забирающий из файла координаты «городов», методы, позволяющие добавлять и удалять «города».
//Унаследуете от «Swarm» новый класс «SwarmGeneral», в котором можно задавать таблицу смежности «городов»(не из каждого «города» есть дорога в другой).
//С помощью класса «Swarm» и «SwarmGeneral» найдите оптимальный путь движения между городами.
