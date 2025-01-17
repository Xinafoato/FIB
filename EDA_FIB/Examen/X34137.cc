#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>>& g, vector<bool>& vis, int u) {
    if (vis[u]) return;
    vis[u] = true;
    for(int v : g[u]) {
        dfs(g, vis, v);
    }
}

int main() {
    int n, u, v, m;
    while(cin >> n >> u >> v >> m) {
        vector<vector<int>> g(n);
        vector<vector<int>> inv(n);
        while(m--) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            inv[y].push_back(x);
        }
        vector<bool> fwd(n, false);
        dfs(g, fwd, u);
        if(!fwd[v]) cout << 0 << endl;
        else {
            vector<bool> fwd2(n, false);
            dfs(inv, fwd2, v);
            int sum = 0;
            for(int i  = 0; i < n; ++i) {
                if(fwd[i] and fwd2[i]) ++sum;
            }
            cout << sum -2 << endl;
        }
    }
}