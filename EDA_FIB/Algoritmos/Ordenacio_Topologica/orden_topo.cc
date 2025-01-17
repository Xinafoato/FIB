#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

// Función que realiza una ordenación topológica sobre un grafo dirigido acíclico (DAG)
list<int> ordenacio_topologica(vector<vector<int>>& G) {
    int n = G.size(); // Número de nodos en el grafo
    vector<int> grau(n, 0); // Vector para almacenar el grado de entrada de cada nodo
    
    // Calcular los grados de entrada para cada nodo
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < G[u].size(); ++i) {
            ++grau[G[u][i]]; // Incrementa el grado de entrada del nodo adyacente
        }
    }

    // Pila para almacenar los nodos con grado de entrada 0
    stack<int> gzero;
    for (int u = 0; u < n; ++u) {
        if (grau[u] == 0) { // Si el nodo tiene grado de entrada 0
            gzero.push(u); // Añadir el nodo a la pila
        }
    }

    // Lista para almacenar el orden topológico
    list<int> orden;

    // Procesar los nodos en la pila
    while (!gzero.empty()) {
        int u = gzero.top(); // Obtener el nodo en la parte superior de la pila
        gzero.pop(); // Eliminar el nodo de la pila
        orden.push_back(u); // Añadir el nodo a la lista de salida

        // Reducir el grado de entrada de los nodos vecinos
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i]; // Nodo vecino
            if (--grau[v] == 0) { // Reducir su grado de entrada y comprobar si llega a 0
                gzero.push(v); // Si el grado de entrada es 0, añadir el nodo a la pila
            }
        }
    }

    // Retornar la lista con el orden topológico
    return orden;
}