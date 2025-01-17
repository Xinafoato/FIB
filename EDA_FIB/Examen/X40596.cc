#include <iostream>
#include <vector>
using namespace std;

int n, d;

bool equilibrat(int ant, int act) {
    return abs(act - ant) <= d;
}

void permutacions(vector<int>& sol, vector<bool>& used, int idx) {
    if (idx == n) {
        cout << '(';
        int j = 0;
        for(int i : sol) {
            if(j == 0) cout << i;
            else cout << ',' << i;
            ++j;
        }cout << ')' << endl;
    }
    else {
        for(int i = 1; i <= n; ++i) {
            if(!used[i]) {
                if(idx == 0 || equilibrat(sol[idx-1], i)) {
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
    cin >> n >> d;
    vector<int> sol(n);
    vector<bool> used(n+1, false);
    permutacions(sol, used, 0);
}