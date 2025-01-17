#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int bestcost;
vector<int> bestsol;

void minmania(const vector<vector<int>>& m, vector<bool>& used, vector<int>& sol, int idx, int cost) {
    if (cost >= bestcost) return;
    int n = sol.size();
    if (idx == n) {
        if (cost < bestcost) {
            bestcost = cost;
            bestsol = sol;
        }
    }
    else {
        for (int i = 1; i < n; ++i) {
            if (!used[i]) {
                sol[idx] = i;
                used[i] = true;
                minmania(m, used, sol, idx+1, cost + m[sol[idx-1]][i]);
                used[i] = false;
            }
        }
    }
}

void escriu_minmania(const vector<vector<int>>& m, const vector<string>& persones) {
    int n = persones.size();

    vector<int> sol(n);
    vector<bool> used(n, false);

    bestcost = numeric_limits<int>::max();
    sol[0] = 0;
    used[0] = true;
    minmania(m, used, sol, 1, 0);

    cout << bestcost << endl;
    for(int i = 0; i < n; ++i) {
        if (i == 0) cout << persones[bestsol[i]];
        else cout << ' ' << persones[bestsol[i]];
    }cout << endl;
}

int main () {
    int n;
    while(cin >> n) {
        vector<string> persones(n);
        for(int i = 0; i < n; ++i) cin >> persones[i];
        vector<vector<int>> m(n, vector<int>(n));

        for(int i =0; i < n; ++i) {
            for(int j = 0; j < n; ++j) cin >> m[i][j];
        }
        escriu_minmania(m, persones);
    }
}