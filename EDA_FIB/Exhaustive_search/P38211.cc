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

void reina_movs(vector<int> & t, vector<bool>& col, vector<bool>& d1, vector<bool>& d2, int idx, bool& b) {
    if(!b) {
        if (idx == n) {
            for(int i = 0; i < n; ++i) {
                for (int j = n-1; j >= 0; --j) {
                    if (t[i] == j) cout << 'Q';
                    else cout << '.';
                }
                cout << endl;
            }
         
            b = true;
        }
        else {
            for(int j = n-1 ; j >= 0; --j) {
                t[idx] = j;
                if (not col[j] and not d1[ld_d1(idx, j)] and not d2[ld_d2(idx, j)]) {
                    col[j] = d1[ld_d1(idx, j)] = d2[ld_d2(idx, j)] = true;
                    reina_movs(t, col, d1, d2, idx+1, b);
                    col[j] = d1[ld_d1(idx, j)] = d2[ld_d2(idx, j)] = false;
                }
            }
   
        }
    }

    
    
}

void compte_reinas() {
    bool b = false;
    vector<int> t (n);
    vector<bool> col(n, false), d1(2*n-1, false), d2(2*n-1, false); 
    reina_movs(t, col, d1, d2, 0, b);
    if(!b) cout << "NO SOLUTION" << endl;
}

int main() {
    cin >> n;
    compte_reinas();
    
}