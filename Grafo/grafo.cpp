#include "grafo.hpp"

#include <cmath>

#define linha_final 0
#define coluna_final 4

Grafo::Grafo(int v) : vertices(v) {
    adj.resize(v);
    manhattan.resize(v);

    addVertice(0, { 0, 0 });
    addVertice(1, { 0, 1 });
    addVertice(2, { 0, 2 });
    addVertice(3, { 0, 3 });
    addVertice(4, { 0, 4 });

    addVertice(5, { 1, 0 });
    addVertice(6, { 1, 1 });
    addVertice(7, { 1, 2 });
    addVertice(8, { 1, 3 });
    addVertice(9, { 1, 4 });

    addVertice(10, { 2, 0 });
    addVertice(11, { 2, 1 });
    addVertice(12, { 2, 2 });
    addVertice(13, { 2, 3 });
    addVertice(14, { 2, 4 });

    addVertice(15, { 3, 0 });
    addVertice(16, { 3, 1 });
    addVertice(17, { 3, 2 });
    addVertice(18, { 3, 3 });
    addVertice(19, { 3, 4 });

    addVertice(20, { 4, 0 });
    addVertice(21, { 4, 1 });
    addVertice(22, { 4, 2 });
    addVertice(23, { 4, 3 });
    addVertice(24, { 4, 4 });

    addAresta(20, 21);
    addAresta(20, 15);
    addAresta(15, 10);
    addAresta(21, 22);
    addAresta(21, 16);
    addAresta(16, 11);
    addAresta(22, 23);
    addAresta(11, 12);
    addAresta(23, 24);
    addAresta(12, 13);
    addAresta(12, 17);
    addAresta(24, 19);
    addAresta(17, 18);
    addAresta(19, 18);
    addAresta(13, 14);
    addAresta(13, 8);
    addAresta(8, 7);
    addAresta(7, 2);
    addAresta(7, 6);
    addAresta(6, 5);
    addAresta(2, 3);
    addAresta(5, 0);
    addAresta(0, 1);
    addAresta(3, 4);
    addAresta(4, 9);
}

void Grafo::addVertice(const int v, pair<int, int> coordenada) {
    addHeuristicaManhattan(v, coordenada);
}

void Grafo::addHeuristicaManhattan(const int v, pair<int, int> coordenada) {
    const int distancia = abs(coordenada.first - linha_final) + abs(coordenada.second - coluna_final);
    manhattan[v] = distancia;
}

void Grafo::addAresta(const int u, const int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Grafo::imprimir() const {
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (int vizinho : adj[i]) {
            cout << vizinho << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> &Grafo::getAdjList() {
    return adj;
}

vector<int> &Grafo::getHeuristica() {
    return manhattan;
}

int Grafo::getNumVertices() const {
    return vertices;
}