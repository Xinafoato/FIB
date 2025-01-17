#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;


typedef vector<vector<char>> VVc;
typedef vector<vector<int>> VVi;

int inf = numeric_limits<int>::max();
vector<pair<int,int>> direc{{1,0},{-1,0},{0,1},{0,-1}};

bool ok(int f, int c, int n, int m, const VVc& M) {
    return f >= 0 && f < n && c >= 0 && c < m && M[f][c] != '#';
}

pair<int,int> cerca(VVc& M) {
    int n = M.size();
    int m = M[0].size();

    VVi dist(n,vector<int>(m,inf));//distacia 
    VVi pers(n,vector<int>(m,-1)); //persones trobades
    queue<pair<int,int>> untracted;

    dist[0][0] = 0;
    pers[0][0] = (M[0][0] == 'P');
    untracted.push({0,0});

    while(!untracted.empty()) {
        int i = untracted.front().first;
        int j = untracted.front().second;
        untracted.pop();

        if(M[i][j] == 'T') return {dist[i][j], pers[i][j]};

        for(auto& d : direc) {
            if(ok(i+d.first, j+d.second, n, m, M)) {
                int newd = dist[i][j] +1;
                int newp = pers[i][j] + (M[i+d.first][j+d.second] == 'P');

                if(dist[i+d.first][j+d.second] == inf) {
                    dist[i+d.first][j+d.second] = newd;
                    pers[i+d.first][j+d.second] = newp;

                    untracted.push({i+d.first,j+d.second});
                }
                else if(dist[i+d.first][j+d.second] == newd && pers[i+d.first][j+d.second] < newp) {
                    pers[i+d.first][j+d.second] = newp;
                }
            }
        }
    }
    return {-1,0};
}

int main() {
    int n,m;
    while(cin >> n >> m) {
        VVc M(n,vector<char>(m));
        bool exist = false;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> M[i][j];
                if(M[i][j] == 'T') exist = true;
            }
        }

        if(!exist) cout << "El telecos ha fugit." << endl;

        else {
            pair<int,int> aux = cerca(M);
            if(aux.first == -1) cout << "El telecos esta amagat." << endl;
            else {
                cout << aux.first << ' ' << aux.second << endl;
            }
        }
    }
}