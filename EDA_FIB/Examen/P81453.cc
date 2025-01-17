///DXTRA NO! PROVAR BFS///
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Graf;


void bfs (Graf& g, vector<int>& path, int fi) {
    int n = g.size();
    vector<bool> visted(n, false);
    vector<int> parent(n, -1);      // Vector para guardar el camino
    queue<int> untrated;
    untrated.push(0);
    visted[0] = true;

    while (!untrated.empty()) {
        int u = untrated.front();
        untrated.pop();
        if (u == fi) {
            int current = fi;
            while (current != -1) { // Reconstrucción del camino
                path.push_back(current);
                current = parent[current];
            }
            reverse(path.begin(), path.end());
            return;
        }

        for(int v : g[u]) {
            if (!visted[v]) {
                visted[v] = true;
                parent[v] = u; // Guardar el nodo padre
                untrated.push(v);
            }
        }
        
    }
    
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        for (int i = 0; i < m; ++i) {
            int aux1, aux2;
            cin >> aux1 >> aux2;
            g[aux1].push_back(aux2);
        }
        for(int i = 0; i < n; ++i) {
            sort(g[i].begin(),g[i].end());
        }
        vector<int> path;
        bfs(g, path, n-1);

        for (int i = 0; i < path.size(); ++i){
            if (i == 0) cout << path[i];
            else cout << ' ' << path[i];}
        cout << endl;
    }
}