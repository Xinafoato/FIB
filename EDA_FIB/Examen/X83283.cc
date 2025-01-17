#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int lluña (const vector<vector<int>>& G) {
    int n = G.size();
    vector<int> dist(n, -1);
    queue<int> untracted;

    untracted.push(0);
    dist[0] = 0;

    while(!untracted.empty()) {
        int u = untracted.front();
        untracted.pop();

        for(int v : G[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u]+1;
                untracted.push(v);
            }
        }
    }

    int result = 0;
    for (int v = 1; v < n; ++v) {
        if(dist[v] != -1 && dist[v] > dist[result]) {
            result = v;
        }
    }
    return result;
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<vector<int>> G(n);
        for(int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        cout << lluña(G) << endl;
    }
}