#include <iostream>
#include <vector> 
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
typedef vector<vector<char>> Graf;

const vector<pair<int,int>> dirs = { {0,1}, {0,-1}, {1,0}, {-1,0} };


bool ok_vei (Graf& T, int f, int c) {
  int n = T.size();
  int m = T[0].size();
  return (f >= 0 and f < n and c >= 0 and c < m and T[f][c] != 'X');
}

void bfs_tresosr(Graf& g, vector<int>& distancia, int f_ini, int c_ini) {
    int n = g.size();
    int m = g[0].size();

    vector<vector<int>> dist(n,vector<int>(m,INF));

    dist[f_ini][c_ini] = 0;

    queue<pair<int, int>> q;
    q.push({f_ini,c_ini});

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        //visitem veins
        for(const pair<int,int>& d : dirs) {
            int f_v = u.first + d.first;
            int c_v = u.second + d.second;

            if(ok_vei(g, f_v, c_v) and dist[f_v][c_v] == INF) {
                q.push({f_v, c_v});
                dist[f_v][c_v] = dist[u.first][u.second] +1;
                if (g[f_v][c_v] == 't') distancia.push_back(dist[f_v][c_v]);
            }
        }
    }
}

int main() {
    int n, m, f, c;
    cin >> n >> m;
    Graf g(n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    cin >> f >> c;

    vector<int> distancia;

    bfs_tresosr(g, distancia, f, c);

    if(distancia.size() < 2) cout << "no es pot arribar a dos o mes tresors" << endl;
    else {
        int segon_lluny = distancia.size() -2;
        cout << "segona distancia maxima: " << distancia[segon_lluny];
    }
}