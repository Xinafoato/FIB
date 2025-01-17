#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<pair<int,int>> movs_c{{1,2},{-1,2},{1,-2},{-1,-2},
                             {2,1},{2,-1},{-2,1},{-2,-1}};

bool ok (int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

