#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

vector<pair<int,int>> moves{{1,2},{-1,2},{1,-2},{-1,-2},
                            {2,1},{2,-1},{-2,1},{-2,-1}};



bool ok(int i, int j, vector<vector<char>>& cuadra, int n, int m) {
    return i >=0 && i < n &&
           j >=0 && j < m &&
           cuadra[i][j] != 'X';
}

int pastanaga(vector<vector<char>>& cuadra, int i_ini, int j_ini) {
    int n = cuadra.size();
    int m = cuadra[0].size();
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pair<int,int>> untracted;

    untracted.push({i_ini,j_ini});
    dist[i_ini][j_ini] = 0;

    while(!untracted.empty()) {
        pair<int, int> nodo = untracted.front();
        untracted.pop();

        for(auto v : moves) {
            int i = nodo.first + v.first;
            int j = nodo.second + v.second;
            if(ok(i, j, cuadra, n ,m) && dist[i][j] == -1) {
                dist[i][j] = dist[nodo.first][nodo.second] +1;
                if (cuadra[i][j] == 'p') {
                    return dist[i][j];
                }
                untracted.push({i,j});
            }
        }
    }

    return -1;
}

int main() {
    int n, m;

    while(cin >> n >> m) {
        vector<vector<char>> cuadra (n, vector<char>(m));
        int i_ini, j_ini;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> cuadra[i][j];
            }
        }
        cin >> i_ini >> j_ini;

        int sol = pastanaga(cuadra, i_ini-1, j_ini-1);

        if (sol == -1) cout << "no" << endl;
        else cout << sol << endl;
    }
   
}