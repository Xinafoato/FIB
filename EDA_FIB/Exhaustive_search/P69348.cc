#include <iostream>
#include <vector>
using namespace std;

void escriure (vector<int> & sol) {
    for (int  i = 0; i < sol.size(); ++i) {
        if (i == 0)  cout << "(" << sol[i] << ",";
        else if (i == sol.size()-1) cout << sol[i];
        else cout << sol[i] << ",";
    } cout << ")" << endl;
}

void permutacions(vector<int>& sol, vector<bool>& usat, int idx) {
    if(idx == sol.size()) {
        escriure(sol);
    }
    else {
        for(int i = 1; i < sol.size()+1; ++i) {
            if(!usat[i]) {
                sol[idx] = i;
                usat[i] = true;
                permutacions(sol, usat, idx +1);
                usat[i] = false;
            }
        }
    }
}

void permutacions(int n) {
    vector<int> sol(n);
    vector<bool> usat(n+1, false);
    int idx = 0;
    permutacions(sol, usat, idx);
}

int main() {
    int n;
    cin >> n;
    if(n != 0) permutacions(n);
}