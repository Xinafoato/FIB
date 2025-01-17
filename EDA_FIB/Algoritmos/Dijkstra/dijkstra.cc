#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

// Tipo de dato para representar un arco: (peso, destino)
typedef pair<double, int> ArcP; 

// Tipo de dato para representar el grafo: lista de adyacencia de arcos
typedef vector< vector<ArcP> > GrafP; 

// Función para ejecutar el algoritmo de Dijkstra
void dijkstra(const GrafP& G, int s, vector<double>& d, vector<int>& p) {
    int n = G.size(); // Número de nodos en el grafo
    double infinit = numeric_limits<double>::infinity(); // Valor infinito para inicializar distancias

    // Inicialización de las distancias y predecesores
    d = vector<double>(n, infinit); // Establece todas las distancias a infinito
    d[s] = 0; // La distancia al nodo fuente es 0
    p = vector<int>(n, -1); // Inicializa los predecesores con -1 (sin predecesor)
     
    // Vector para marcar los nodos procesados
    vector<bool> S(n, false); 

    // Cola de prioridad que almacenará pares (peso, nodo)
    // La cola siempre devuelve el nodo con la distancia más corta
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> Q;

    // Insertamos el nodo fuente con distancia 0
    Q.push(ArcP(0, s)); 

    // Bucle principal del algoritmo de Dijkstra
    while (not Q.empty()) {
        int u = Q.top().second; // Extrae el nodo con la menor distancia estimada
        Q.pop(); // Elimina el nodo de la cola
        
        // Si el nodo no ha sido procesado aún
        if (not S[u]) { 
            S[u] = true; // Marca el nodo como procesado

            // Recorre los vecinos del nodo u
            for (int i = 0; i < int(G[u].size()); ++i) {
                int v = G[u][i].second; // Nodo vecino
                int c = G[u][i].first;  // Peso del arco (u, v)

                // Si se encuentra un camino más corto hacia v
                if (d[v] > d[u] + c) { 
                    d[v] = d[u] + c;   // Actualiza la distancia de v
                    p[v] = u;          // Actualiza el predecesor de v
                    Q.push(ArcP(d[v], v)); // Añade el vecino a la cola con su nueva distancia
                }
            }
        }
    }
}