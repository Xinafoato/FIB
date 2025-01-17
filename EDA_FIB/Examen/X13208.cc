#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int,int> cell;
typedef vector<vector<int>> Mat;

int inf = numeric_limits<int>::max();
vector<cell> direc = {{0,-1},{0,1},{1,0},{-1,0}};

bool ok(cell& c, int n) {
    return c.first == 0 || c.second == 0 || c.first == n-1 || c.second == n-1;
}

int cost(Mat& m) {
    int n = m.size();
    cell center = {n/2, n/2};

    Mat dist(n, vector<int>(n,inf));
    Mat removed(n, vector<int>(n, 0));

    priority_queue<pair<int,cell>, vector<pair<int,cell>>, greater<pair<int,cell>>> untracted;
    dist[center.first][center.second] = m[center.first][center.second];
    untracted.push({dist[center.first][center.second], center});

    while(!untracted.empty()) {
        cell u = untracted.top().second;
        untracted.pop();

        if(!removed[u.first][u.second]) {
            removed[u.first][u.second] = 1;
            if (ok(u, n)) return dist[u.first][u.second];
            for(auto& d : direc) {
                cell v = {u.first+d.first, u.second+d.second};

                if( dist[u.first][u.second] +m[v.first][v.second] <  dist[v.first][v.second]) {
                    dist[v.first][v.second] = dist[u.first][u.second] +m[v.first][v.second];
                    untracted.push({dist[v.first][v.second], v});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    while(cin >> n) {
        Mat m(n, vector<int>(n));

        for(int i = 0; i <n; ++i) {
            for(int j = 0; j < n; ++j) cin >> m[i][j];
        }
        cout << cost(m) << endl;
    }
    

}