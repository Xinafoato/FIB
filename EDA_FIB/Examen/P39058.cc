#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int INF = numeric_limits<int>::max();
vector<pair<int,int>> moves{{1,2},{-1,2},{1,-2},{-1,-2},
                            {2,1},{2,-1},{-2,1},{-2,-1}};

int n, m;

bool ok(int i, int j, vector<vector<char>>& cuadra) {
    return i >=0 && i < n &&
           j >=0 && j < m &&
           cuadra[i][j] != 'a';
}

pair<int,double> alcanzable(vector<vector<char>>& cuadra, int i_ini, int j_ini) {
    vector<vector<int>> dist(n,vector<int>(m,INF));
    queue<pair<int,int>> untracted;
    untracted.push({i_ini,j_ini});
    dist[i_ini][j_ini] = 0;

    int flors = 0;
    int sumdist = 0;

    while(!untracted.empty()) {
        pair<int, int> nodo = untracted.front();
        untracted.pop();

        for(auto v : moves) {
            int i = nodo.first + v.first;
            int j = nodo.second + v.second;
            if(ok(i, j, cuadra) && dist[i][j] == INF) {
                dist[i][j] = dist[nodo.first][nodo.second] +1;
                untracted.push({i,j});
                if (cuadra[i][j] == 'F') {
                    ++flors;
                    sumdist += dist[i][j];
                }
            }
        }
    }

    if(flors != 0) return {flors, double(sumdist)/flors};
    return {0,0};
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    cin >> n >> m;
    vector<vector<char>> cuadra (n, vector<char>(m));
    int i_ini, j_ini;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> cuadra[i][j];
            if(cuadra[i][j] == 'C') {
                i_ini = i;
                j_ini = j;
            }
        }
    }

    pair<int, double> sol = alcanzable(cuadra, i_ini, j_ini);

    if (sol.first > 0) {
        cout << "flors accessibles: " << sol. first << endl;
        cout << "distancia mitjana: "<< sol.second << endl;
    }
    else {
        cout << "el cavall no pot arribar a cap flor" << endl;
    }
}