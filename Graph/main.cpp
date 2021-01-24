#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    char file[] = "TestGraph.txt";
    Graph graph(file);
    // Answer: 18
    cout << "Answer: " << graph.connectivityComponent(); 
    return 0;
}