#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graf;

void llegir_graf(Graf& g, int m) {
    int x, y;
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

bool es_bipartit(Graf& g, int n) {
    vector<int> color(n, -1);      // -1: No pintado, 0: Color 1, 1: Color 2

    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) { // Si no está visitado
            queue<int> q;
            q.push(i);
            color[i] = 0; // Pintamos el nodo inicial con el color 0

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (color[v] == -1) {
                        // Pintamos el vecino con el color opuesto
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // Si dos vecinos tienen el mismo color, no es bipartito
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        llegir_graf(g, m); //llista d'adjacència
        if(es_bipartit(g,n)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}