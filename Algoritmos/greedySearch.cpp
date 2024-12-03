#include "greedySearch.hpp"
#include "PriorityQueue/priorityQueue.hpp"
#include <string>
#include <stack>
#include <limits>
#include <chrono>
#include <memory>

void GreedySearch::executar(Grafo &grafo, int inicial, int final) {
    int vertices = grafo.getNumVertices();
    vector<vector<int>> &adj = grafo.getAdjList();
    vector<int> &heuristica = grafo.getHeuristica();

    ofstream out("caminhoBuscaGulosa.txt");

    if (!out.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }

    auto start = chrono::high_resolution_clock::now();

    vector<bool> visited(vertices, false);
    vector<int> pi(vertices, -1);
    vector<int> d(vertices, numeric_limits<int>::max());
    int iteracao = 0;

    out << "================================" << endl;
    out << "INÍCIO DA BUSCA GULOSA (GREEDY SEARCH)" << endl;
    out << "================================" << endl;
    out << "Nó Inicial: " << inicial << endl;
    out << "Nó Final: " << final << endl;
    out << "================================" << endl;

    d[inicial] = 0;
    pi[inicial] = -1;

    PriorityQueue *filaPrioridade = new PriorityQueue();
    filaPrioridade->Enqueue(inicial, heuristica[inicial]);
    bool found = false;

    while (!filaPrioridade->Empty() && !found) {
        iteracao++;
        int u = filaPrioridade->Front()->getVertex();
        filaPrioridade->Dequeue();

        out << "\nIteração " << iteracao << ": Explorando nó " << u << endl;
        out << "  Distância da origem: " << d[u] << ", Predecessor: " << pi[u] << endl;

        out << "  Vizinhos do nó " << u << ":" << endl;
        bool algumNaoVisitado = false;

        for (int v : adj[u]) {
            if (!visited[v]) {
                out << "    - Explorando vizinho " << v << " (NÃO VISITADO)" << endl;
                visited[v] = true;
                d[v] = d[u] + 1;
                pi[v] = u;
                filaPrioridade->Enqueue(v, heuristica[v]);

                if (v == final) {
                    found = true;
                    out << "    *** NÓ FINAL " << final << " ENCONTRADO! ***" << endl;
                    break;
                }

                algumNaoVisitado = true;
            } else {
                out << "    - Vizinho " << v << " (JÁ VISITADO)" << endl;
            }
        }

        if (!algumNaoVisitado) {
            out << "  Todos os vizinhos de " << u << " já foram visitados." << endl;
        }

        visited[u] = true;
        out << "  Nó " << u << " visitado!" << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    out << "\n================================" << endl;
    out << "RESUMO DA BUSCA" << endl;
    out << "================================" << endl;

    if (found) {
        out << "\nNó " << final << " encontrado!" << endl;
        out << "Distância do nó " << inicial << " até o nó " << final
            << ": " << d[final] << endl;

        out << "\nCAMINHO ENCONTRADO:" << endl;
        printPath(pi, final, out);
    } else {
        out << "Não foi possível encontrar um caminho até o nó " << final << endl;
    }

    out << "\n================================" << endl;
    out << "ESTATÍSTICAS DE EXECUÇÃO" << endl;
    out << "================================" << endl;
    out << "Tempo de execução: " << duration.count() << " ms" << endl;
    out << "Memoria Usada: " << filaPrioridade->GetMemoriaTotalUsada() << " bytes" << endl;

    out.close();
}

void GreedySearch::printPath(vector<int> &pi, int target, ofstream &out) {
    stack<int> path;
    int current = target;

    while (current != -1) {
        path.push(current);
        current = pi[current];
    }

    while (!path.empty()) {
        out << path.top();
        path.pop();
        if (!path.empty()) out << " -> ";
    }
    out << endl;
}
