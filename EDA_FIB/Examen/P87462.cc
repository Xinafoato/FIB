#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Map;

vector<pair<int,int>> movedirs = {{0,1},{0,-1},{-1,0},{1,0}};
vector<pair<int,int>> alldirs = {{0,1},{0,-1},{-1,0},{1,0},
                                 {1,1},{1,-1},{-1,1},{-1,-1}};

bool segura (Map& m,  int i, int j) {
    for(auto& d : alldirs) {
        if(m[i+d.first][j+d.second] == 'F') return false;
    }
    return true;
}

bool alcanzable(Map& m, int i, int j) {
    if(m[i][j] == 'X') return false;
    if(!segura(m, i, j)) return false;
    if(m[i][j] == 'B') return true;

    m[i][j] = 'X';
    for(auto& d : movedirs) {
        if(alcanzable(m, i+d.first, j+d.second)) return true;
    }
    return false;
}

int main() {
    int f, c;
    while(cin >> f >>c) {
        Map m(f, vector<char>(c));
        int i_ini = -1 , j_ini = -1;

        for(int i = 0; i < f; ++i) {
            for(int j = 0; j < c; ++j) {
                cin >> m[i][j];
                if(m[i][j] == 'P') {
                    i_ini = i; 
                    j_ini = j;
                }
            }
        }

        if(alcanzable(m, i_ini, j_ini)) cout << "si" << endl;
        else cout << "no" << endl;
    }
}