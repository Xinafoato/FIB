#include <iostream>
#include <vector>
using namespace std;

int u;

void escriure_tire(vector<bool> & sol, int idx, int z, int k) {
    if (idx == sol.size()) {
        
        int i = 0;
        for(bool b : sol) {
            if (i == 0) cout << b;
            else cout << " " << b;
            ++i;
        } cout << endl;
        
    }
    else {
        if (z < sol.size() - u) { // falten 0's
            sol[idx] = false; // 0
            escriure_tire(sol, idx +1, z +1, k);
        }
        if (k < u) {    // falten 1's
            sol[idx] = true; // 1
            escriure_tire(sol, idx +1, z, k +1); 
        }
        
    }
}

void escriure_tires(int n) {
    vector<bool> sol(n);
    int idx = 0;
    int k = 0, z = 0;
    escriure_tire(sol, idx, z, k);
}

int main() {
    int n;
    cin >> n >> u;
    escriure_tires(n);
}