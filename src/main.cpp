#include "greedySearch.hpp"
#include "aStar.hpp"

int main() {
    const int numVertices = 25;

    Grafo grafo(numVertices);

    cout << "Listas de adjacência do Grafo:" << endl;
    grafo.imprimir();
    cout << endl;
    GreedySearch::executar(grafo, 20, 4);
    cout << "Caminhos e processos da Busca Gulosa e do A* salvos nos arquivos txt" << endl;

    return 0;
}
/*
0 1_|2 3_ 4
5_ 6_ 7_ 8| 9_
10| 11 12 13_ 14_
15| 16| 17_ 18_ 19
20 21 22 23 24
*/