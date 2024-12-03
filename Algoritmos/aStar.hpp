#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "Grafo/grafo.hpp"
#include <vector>
#include <fstream>

using namespace std;

class A_Star {
public:
    static void executar(Grafo &grafo, int inicial, int final);
    static void printPath(vector<int> &pi, int target, ofstream &out);
};

#endif