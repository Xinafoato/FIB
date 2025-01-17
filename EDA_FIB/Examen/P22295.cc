#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> Direccio {{0,1},{0,-1},{1,0},{-1,0}};
int n, m;

bool ok(int i_c, int j_c) {
    return i_c >= 0 && i_c < n && j_c >= 0 && j_c < m;
}

void camitortuga(vector<pair<int,int>>& sol, vector<vector<char>>& map, vector<vector<bool>>& visited, int i_f, int j_f) {
    pair<int, int> nodo = sol.back();

    if(nodo.first == i_f and nodo.second == j_f) {
        for(auto i : sol) {
            cout << map[i.first][i.second];
        }cout << endl;
    } 
    else {
        for(auto s : Direccio) {
            pair<int,int> v;
            v.first = nodo.first + s.first;
            v.second = nodo.second + s.second;
            if(ok(v.first, v.second) && !visited[v.first][v.second]) {
                visited[v.first][v.second] = true;
                sol.push_back(v);
                camitortuga(sol, map, visited, i_f, j_f);
                sol.pop_back();
                visited[v.first][v.second] = false;
            }
        }
    }
}

int main () {
    cin >> n >> m;
    vector<vector<char>> map (n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    int i_i, j_i, i_f, j_f;
    cin >> i_i >> j_i >> i_f >> j_f;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> sol;
    sol.push_back({i_i, j_i});
    visited[i_i][j_i] = true;

    camitortuga(sol, map, visited, i_f, j_f);
}