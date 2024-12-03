#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <iostream>
#include <utility> 
using namespace std;

class Grafo {
private:
    int vertices;
    vector<vector<int>> adj;
    vector<int>manhattan;

    void addVertice(const int v, pair<int, int> coordenada);
    void addHeuristicaManhattan(const int v, pair<int, int> coordenada);
    void addAresta(const int u, const int v);

public:
    Grafo(const int v);
    void imprimir() const;
    vector<vector<int>> &getAdjList();
    vector<int> &getHeuristica();
    int getNumVertices() const;
};

#endif