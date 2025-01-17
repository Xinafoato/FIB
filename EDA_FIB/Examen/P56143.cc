#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef vector<vector<char>> Map;
int INF = numeric_limits<int>::max();

vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

void bfs(Map& map, int i_ini, int j_ini) {
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> dist(n,vector<int>(m,INF));
    vector<vector<pair<int,int>>> previ(n, vector<pair<int,int>>(m));
    queue<pair<int,int>> untracted;

    dist[i_ini][j_ini] = 0;
    untracted.push({i_ini, j_ini});

    bool trobat = false;
    int i_pages, j_pages;

    while(!untracted.empty() && !trobat) {
        int i = untracted.front().first;
        int j = untracted.front().second;
        untracted.pop();

        for(auto& d : dirs) {
            int s_i = i + d.first;
            int s_j = j + d.second;

            if(map[s_i][s_j] != 'X' && dist[s_i][s_j] == INF) {
                if (map[s_i][s_j] == 'F') {
                    i_pages = s_i;
                    j_pages = s_j;
                    trobat = true;
                }
                dist[s_i][s_j] = dist[i][j] +1;
                previ[s_i][s_j] = {i,j};
                untracted.push({s_i,s_j});
            }
        }
    }

    if (!trobat) cout << 0 << endl;
    else {
        cout << dist[i_pages][j_pages] +1 << ' ';

        pair<int,int> current = {i_pages, j_pages};
        pair<int,int> desti = {i_ini, j_ini};
        vector<pair<int,int>> cami;

        while(current != desti) {
            cami.push_back(current);
            current = previ[current.first][current.second];
        }
        cami.push_back(desti);

        for(int i = cami.size()-1; i >= 0; --i) {
            if (i == 0) cout << ' ' << cami[i].first << ' ' << cami[i].second;
            else cout << ' ' << cami[i].first << ' ' << cami[i].second << ' ';
        }cout << endl;
    }

} 


int main() {
    int n, m;
    while(cin >> n >> m) {
        Map map(n, vector<char>(m));
        int i_ini = -1, j_ini = -1;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> map[i][j];
                if (map[i][j] == 'K'){
                    i_ini = i;
                    j_ini = j;
                }
            }
        }
        bfs(map, i_ini, j_ini);
    }
}