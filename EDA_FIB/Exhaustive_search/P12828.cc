#include <iostream>
#include <vector>
using namespace std;

void escriure_tire(vector<bool> & sol, int idx) {
    if (idx == sol.size()) {
        int i = 0;
        for(bool b : sol) {
            if (i == 0) cout << b;
            else cout << " " << b;
            ++i;
        } cout << endl;
    }
    else {
        sol[idx] = false; // 0
        escriure_tire(sol, idx+1);
        sol[idx] = true; // 1
        escriure_tire(sol, idx+1);
    }
}

void escriure_tires(int n) {
    vector<bool> sol(n);
    int idx = 0;
    escriure_tire(sol, idx);
}

int main() {
    int n;
    cin >> n;
    escriure_tires(n);
}