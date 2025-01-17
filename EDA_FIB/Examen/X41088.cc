#include <iostream>
#include <vector>
using namespace std;

int n;

bool condicion(int l, int m, int r) {
    return l+r > 2*m;
}

void permutacions(vector<int>& sol, vector<bool>& used, int idx) {
    if (idx == sol.size()) {
        cout << '(';
        int j = 0;
        for (int i : sol) {
            if (j == 0) cout << i;
            else cout << ',' << i;
            ++j;
        } cout << ')' << endl;
    }
    else {
        for(int i = 1; i <= n; ++i) {
            if (!used[i]) {
                if(idx <= 1 || !condicion(sol[idx-2], sol[idx-1], i)) {
                    sol[idx] = i;
                    used[i] = true;
                    permutacions(sol, used, idx+1);
                    used[i] = false;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    vector<int> sol(n);
    vector<bool> used(n+1, false);
    permutacions(sol, used, 0);
}