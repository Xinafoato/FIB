#include <iostream>
#include <vector>
using namespace std;

// Función para realizar DFS desde un nodo
void dfs(int nodo, vector<bool>& visitado, const vector<vector<int>>& grafo) {
    // Marca el nodo como visitado
    visitado[nodo] = true;
    cout << nodo << " "; // Imprime el nodo actual (puedes personalizar esta acción)

    // Recorre los nodos adyacentes al nodo actual ej vecinos del nodo 0 {1,2,3} entonces cada iteración sera 1, 2, y 3;
    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) {
            dfs(vecino, visitado, grafo); // Llama recursivamente para el vecino
        }
    }
}

// Función para inicializar DFS
void inicializarDFS(int numNodos, const vector<vector<int>>& grafo) {
    vector<bool> visitado(numNodos, false); // Vector para marcar nodos visitados

    // Llamar a DFS para todos los nodos no visitados (para manejar grafos no conexos)
    for (int i = 0; i < numNodos; i++) {
        if (!visitado[i]) {
            cout << "Iniciando DFS desde el nodo " << i << ":\n";
            dfs(i, visitado, grafo);
            cout << endl;
        }
    }
}