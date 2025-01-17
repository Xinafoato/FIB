#include <iostream>
#include <vector>
using namespace std;

void escriure (vector<int> & sol, vector<string>& p) {
    
    for (int  i = 0; i < sol.size(); ++i) {
        if (i == 0)  cout << "(" << p[sol[i]] << ",";
        else if (i == sol.size()-1) cout << p[sol[i]];
        else cout << p[sol[i]] << ",";
    } cout << ")" << endl;
}

void permutacions(vector<string>& p, vector<int>& sol, vector<bool>& usat, int idx) {
    if(idx == sol.size()) {
        escriure(sol, p);
    }
    else {
        for(int i = 0; i < p.size(); ++i) {
            if(!usat[i]) {
                sol[idx] = i;   
                usat[i] = true;
                permutacions(p, sol, usat, idx +1);
                usat[i] = false;
            }
        }
    }
}

void permutacions(vector<string>& p, int n) {
    vector<int> sol(n);
    vector<bool> usat(n, false);
    int idx = 0;
    permutacions(p, sol, usat, idx);
}

int main() {
    int n;
    cin >> n;
    vector<string> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];
    if(n != 0) permutacions(p, n);
}