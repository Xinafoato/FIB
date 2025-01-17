#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>
using namespace std;

// Definimos el tipo "graph" como un vector de listas de enteros.
typedef vector<list<int>> graph;

// Función que realiza BFS en un grafo representado como listas de adyacencia.
list<int> bfs(const graph& G) {
    int n = G.size();              // Número de nodos en el grafo.
    list<int> L;                   // Lista para almacenar el recorrido BFS.
    queue<int> Q;                  // Cola para manejar el orden de exploración.
    vector<bool> enc(n, false);    // Vector para marcar nodos visitados.

    // Recorremos todos los nodos del grafo para manejar componentes desconectados.
    for (int u = 0; u < n; ++u) {
        if (!enc[u]) {             // Si el nodo `u` no ha sido visitado:
            Q.push(u);             // 1. Lo añadimos a la cola.
            enc[u] = true;         // 2. Lo marcamos como visitado.

            // Procesamos todos los nodos alcanzables desde el nodo `u`.
            while (!Q.empty()) {
                int v = Q.front(); // Tomamos el nodo al frente de la cola.
                Q.pop();           // Lo eliminamos de la cola.
                L.push_back(v);    // Añadimos el nodo al recorrido BFS.

                // Exploramos los vecinos del nodo actual `v`.
                for (int w : G[v]) {
                    if (!enc[w]) { // Si el vecino `w` no ha sido visitado:
                        Q.push(w); // 1. Lo añadimos a la cola.
                        enc[w] = true; // 2. Lo marcamos como visitado.
                    }
                }
            }
        }
    }
}


typedef vector<vector<int>> graf;

void bfs_dis(const graf& g, int ini, vector<int> distance) {
    int n = g.size();
    int infinit = numeric_limits<int>::max();

    distance = vector<int>(n, infinit);
    distance[ini] = 0;
    vector<bool> visited;
    queue<int> untracted;

    untracted.push(ini);
    while (not untracted.empty()) {
        int u = untracted.front();
        untracted.pop();

        if(u )

        if(not visited[u]) {
            for(int i = 0; i < g[u].size(); ++i) {
                int v = g[u][i];
                if (distance[v] > distance[u]+1) {
                    distance[v] = distance[u]+1;
                    untracted.push(v);
                }
            }
        }
    }
}

typedef vector<vector<int>> Graf;

void bfs(const Graf& g, int start, int target) {
    int n = g.size();
    vector<bool> visited(n, false); // Para rastrear los nodos visitados
    vector<int> parent(n, -1);     // Para reconstruir el camino
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Si llegamos al nodo objetivo
        if (u == target) {
            cout << "Camino encontrado: ";
            vector<int> path;
            for (int v = target; v != -1; v = parent[v])
                path.push_back(v);
            //reverse(path.begin(), path.end());
            for (int node : path)
                cout << node << " ";
            cout << endl;
            return;
        }

        // Explorar vecinos
        for (int v : g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u; // Rastrear el nodo previo
                q.push(v);
            }
        }
    }
}