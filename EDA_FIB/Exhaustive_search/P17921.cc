#include <iostream>
#include <vector>
using namespace std;

int n;

int ld_d1 (int l, int j) {
    return l+j;
}

int ld_d2 (int l, int j) {
    return l-j+(n-1);
}

void reina_movs(vector<int> & t, vector<bool>& col, vector<bool>& d1, vector<bool>& d2, int idx) {
    if (idx == n) {
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (t[i] == j) cout << 'Q';
                else cout << '.';
            }cout << endl;
        }cout << endl;
    }
    else {
        for(int j = 0; j < n; ++j) {
            t[idx] = j;
            if (not col[j] and not d1[ld_d1(idx, j)] and not d2[ld_d2(idx, j)]) {
                col[j] = d1[ld_d1(idx, j)] = d2[ld_d2(idx, j)] = true;
                reina_movs(t, col, d1, d2, idx+1);
                col[j] = d1[ld_d1(idx, j)] = d2[ld_d2(idx, j)] = false;
            }
        }
    }
}

void compte_reinas() {
    vector<int> t (n);
    vector<bool> col(n, false), d1(2*n-1, false), d2(2*n-1, false); 
    reina_movs(t, col, d1, d2, 0);
}

int main() {
    cin >> n;
    compte_reinas();        
}