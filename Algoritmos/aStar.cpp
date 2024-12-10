#include "aStar.hpp"
#include "PriorityQueue/priorityQueue.hpp"
#include <string>
#include <stack>
#include <limits>
#include <chrono>
#include <memory>
#include <cstdlib> 
#include <ctime> 


void A_Star::executar(Grafo &grafo, int inicial, int final) {
    srand(static_cast<unsigned>(time(0)));
    int vertices = grafo.getNumVertices();
    vector<vector<int>> &adj = grafo.getAdjList();
    vector<int> &heuristica = grafo.getHeuristica();

    ofstream out("caminhoAestrela.txt");

    if (!out.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }

    auto start = chrono::high_resolution_clock::now();

    vector<bool> visited(vertices, false);
    vector<int> pi(vertices, -1);
    vector<int> g(vertices, numeric_limits<int>::max()); // Custo do caminho
    vector<int> f(vertices, numeric_limits<int>::max()); // Custo total
    vector<vector<int>> predecessores(vertices);
    int iteracao = 0;

    out << "================================" << endl;
    out << "INÍCIO DA BUSCA A* (A STAR SEARCH)" << endl;
    out << "================================" << endl;
    out << "Nó Inicial: " << inicial << endl;
    out << "Nó Final: " << final << endl;
    out << "================================" << endl;

    g[inicial] = 0;
    f[inicial] = heuristica[inicial];
    pi[inicial] = -1;

    PriorityQueue *filaPrioridade = new PriorityQueue();
    filaPrioridade->Enqueue(inicial, f[inicial]);
    bool found = false;

    while (!filaPrioridade->Empty() && !found) {
        iteracao++;
        int u = filaPrioridade->Front()->getVertex();
        filaPrioridade->Dequeue();

        if (u == inicial) {
            f[u] = 0;
        }

        out << "\nIteração " << iteracao << ": Explorando nó " << u << " f[" << u << "]" << " = " << f[u] << endl;
        //out << "  Predecessores do nó " << u << ":";
        //for (int p : predecessores[u]) {
        //    out << " Nó " << p << " (g[" << p << "] = " << g[p] << ")";
        //}
        out << endl;
        if (u == final) {
            found = true;
            out << "    *** NÓ FINAL " << final << " ENCONTRADO! ***" << endl;
            break;
        }

        bool algumNaoVisitado = false;

        for (int v : adj[u]) {
            int custoAleatorio = rand() % 5 + 1;
            int custo = g[u] + custoAleatorio;

            if (!visited[v]) {
                if (v != final) {
                    visited[v] = true;
                }

                g[v] = custo;
                pi[v] = u;
                f[v] = g[v] + heuristica[v];
                predecessores[v].clear();
                predecessores[v].push_back(u);

                out << "        Distância estimada até o destino (f[" << v << "]): " << f[v]
                    << " (Heurística: " << heuristica[v] << ")" << endl;
                filaPrioridade->Enqueue(v, f[v]);

                algumNaoVisitado = true;
            } else {
                //out << "      - Vizinho " << v << " já visitado ou custo maior" << endl;
            }
        }

        if (!algumNaoVisitado) {
            //out << "  Todos os vizinhos de " << u << " já foram visitados." << endl;
        }

        visited[u] = true;
        out << "  Nó " << u << " marcado como visitado!" << endl;

    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    out << "\n================================" << endl;
    out << "RESUMO DA BUSCA" << endl;
    out << "================================" << endl;

    if (found) {
        out << "\nNó " << final << " encontrado!" << endl;
        out << "Custo do nó " << inicial << " até o nó " << final
            << ": " << g[final] << endl;

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

void A_Star::printPath(vector<int> &pi, int target, ofstream &out) {
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