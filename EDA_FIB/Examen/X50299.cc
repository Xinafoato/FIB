#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int INF = numeric_limits<int>::max();

int dijkstra(const vector<vector<pair<int,int>>>& g, int x, int y) {
    int n = g.size();
    vector<int> distance(n, INF);
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> untracted;
    distance[x] = 0;
    untracted.push({0, x}); //<l, nodo>

    while(!untracted.empty()) {
        auto u = untracted.top();
        untracted.pop();

        if (u.second == y) return distance[u.second];
        if (u.first == distance[u.second]) {
            for(auto p : g[u.second]) {
                int v = p.second;
                int l = p.first;
                int maxl = max(distance[u.second], l);

                if (maxl < distance[v]) {
                    distance[v] = maxl;
                    untracted.push({maxl, v});
                }
            }
        }
    }
    return INF;

}

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<vector<pair<int,int>>> g(n);
        for (int i = 0; i < m; ++i) {
            int x, y , l;
            cin >> x >> y >> l;
            g[x].push_back({l, y});
        }
        cout << dijkstra(g, 0, 1) << endl;
    }
}