#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

typedef pair<int,int> Arista;
typedef vector<vector<Arista>> G;

void dijkstra(const G& g, int x, vector<int>& distance, vector<int>& path, int y) {
    int n = g.size();
    int infinit = numeric_limits<int>::max();

    distance = vector<int>(n, infinit);
    distance[x] = 0;
    path = vector<int>(n,-1);

    vector<bool> visited(n, false);
    priority_queue< Arista, vector<Arista>, greater<Arista>> untracted;

    untracted.push(Arista(0,x));
    while (not untracted.empty()) {
        int u = untracted.top().second;
        untracted.pop();
        if(u == y) return;
        

        if (not visited[u]) {
            visited[u] = true;

            for (int i = 0; i < int(g[u].size()); ++i) {
                int v = g[u][i].second;
                int pes = g[u][i].first;

                if(distance[v] > distance[u] + pes) {
                    distance[v] = distance[u] + pes;
                    path[v] = u;
                    untracted.push(Arista(distance[v], v));
                }
                
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        G g(n);
        for(int i = 0; i < m; ++i) {
           int nodo;
           Arista a;
           cin >> nodo >>a.second >> a.first;
           g[nodo].push_back(a);
        }
        vector<int> distance;
        vector<int> path;
        int x,y;
        cin >> x >> y;

        dijkstra(g,x,distance,path,y);
    
        if (distance[y] == numeric_limits<int>::max()) {
            cout << "no path from " << x << " to " << y << endl;
        }
        else {
            
            stack<int> aux;
            int prev = y;
            
            while (prev != x) {
                aux.push(path[prev]);
                prev = path[prev];
            }
            while (not aux.empty()) {
                cout << aux.top() << ' ';
                aux.pop();
            }cout << y << endl;
        
        }
    }
    
}