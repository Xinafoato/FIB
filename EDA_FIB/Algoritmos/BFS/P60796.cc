#include <iostream>
#include <vector> 
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

//                              dre    esq    avall   amunt
const vector<pair<int,int>> dirs = { {0,1}, {0,-1}, {1,0}, {-1,0} };

bool ok_vei (const vector<vector<char>>& T, int f, int c) {
  int n = T.size();
  int m = T[0].size();

  // if (f >= 0 and f < n and c >= 0 and c < m and T[f][c] != 'X') return true;
  // else return false;
  return (f >= 0 and f < n and c >= 0 and c < m and T[f][c] != 'X'); 
}

int distancia_tresor (const vector<vector<char>>& T, int f_ini, int c_ini) {
  int n = T.size();
  int m = T[0].size();
  vector<vector<int>> dist(n,vector<int>(m,INF));

  dist[f_ini][c_ini] = 0;
  queue<pair<int,int>> Q;
  Q.push({f_ini,c_ini});

  while (not Q.empty()) {
    pair<int,int> u = Q.front();
    Q.pop();

    // Visito els veins de u
    for (const pair<int,int>& d : dirs) {
        int f_v = u.first + d.first;
        int c_v = u.second + d.second;    
        if (ok_vei(T,f_v,c_v) and dist[f_v][c_v] == INF) {
	        Q.push({f_v,c_v});
	        dist[f_v][c_v] = dist[u.first][u.second] + 1;
	        if (T[f_v][c_v] == 't') return dist[f_v][c_v];
        }
    }
  }

  return -1;
}


int main() {
	int n, m, f, c;
	cin >> n >> m;
	
	vector<vector<char>> M(n, vector<char>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j) cin >> M[i][j];
	
    }
	cin >> f >> c;
    int distancia = distancia_tresor(M, f-1, c-1);
	if(distancia == -1) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia minima: " << distancia << endl;
}