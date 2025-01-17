#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graf;

void ordenacio_topologica(const Graf& g) {
    int n = g.size();
    vector<int> grau(n,0);

    //inicialitcem els graus
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < g[i].size(); ++j){
            ++grau[g[i][j]];
        }
    }

    priority_queue<int, vector<int>, greater<int>> gzero;
    for(int i = 0; i < n; ++i){
        if (grau[i] == 0){
            gzero.push(i);
        }
    }

    list<int> orden;

    while(not gzero.empty()) {
        int u = gzero.top();
        gzero.pop();
        orden.push_back(u);

        for(int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if(--grau[v] == 0){
                gzero.push(v);
            }
        }
    }
    int count=0;
        for (int nodo : orden) {
            cout << nodo;
            if (++count < int(orden.size())) cout << ' ';
        }
        cout << endl;
}

void n_topo(const Graf& g, in n) {

}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        for(int i = 0; i < m; ++i){
            int aux1, aux2;
            cin >> aux1 >> aux2;
            g[aux1].push_back(aux2);
        }

        ordenacio_topologica(g);

    }
}