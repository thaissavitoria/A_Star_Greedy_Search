#include "aStar.hpp"
#include "PriorityQueue/priorityQueue.hpp"
#include <chrono>
#include <memory>

void A_Star::executar(Grafo &grafo, int inicial, int final) {
    int vertices = grafo.getNumVertices();
    vector<vector<int>> &adj = grafo.getAdjList();

    ofstream out("caminhoAEstrela.txt");

    if (!out.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }

    auto start = chrono::high_resolution_clock::now();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    out.close();
}

void A_Star::printPath(vector<int> &pi, int target, ofstream &out) {

}