#include <iostream>
#include <vector>
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

void dfs(Graf & g, vector<bool>& visited, int father, int nodo, bool& cicle) {
    
    if(!visited[nodo]) {
        visited[nodo] = true;

        for(int neivor : g[nodo]) {
            if(neivor != father) {
                dfs(g, visited, nodo, neivor, cicle);
                if(cicle) return;
            }
        }
    }
    else cicle = true;
}

void dfsini(Graf& g, int n) {
    vector<bool> visited(n, false);
    int count = 0;

    for(int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bool cicle = false;
            dfs(g, visited, i, i, cicle);
            
            if (cicle) {
                cout << "no" << endl;
                return;
            }
            ++count;
        }
    }
    cout << count << endl;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        llegir_graf(g, m); //llista d'adjacència
        dfsini(g,n);
    }
}