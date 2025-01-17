#include <iostream>
#include <vector>
using namespace std;

int n;

void reis_pacifics(vector<int>& sol, vector<vector<bool>>& atacat, int idx) {
    if (idx == n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (sol[i] == j) cout << 'K';
                else cout << '.';
            }cout << endl;
        }cout << endl;
    }
    else {
        for(int i = 0; i < n; ++i) {
            sol[idx] = i;
            if (!atacat[i])
        }
    }
}