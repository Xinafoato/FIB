#include <iostream>
#include <vector>
using namespace std;

int n;

void transforma(int x) {
    cout << char(x+97);
}

void paraulespro(vector<int>& sol, vector<bool>& usat, int idx, int ant) {
    if (idx == n) {
        for(int i : sol) transforma(i);
        cout << endl;
    }
    else {
        for(int i = 0; i < n; ++i) {
            if(!usat[i] and i != ant+1) {
                sol[idx] = i;
                usat[i] = true;
                paraulespro(sol, usat, idx+1, i);
                usat[i] = false;
            }
        }
    }
}

void paraulespro() {
    vector<int> sol(n);
    vector<bool> usat(n, false);
    paraulespro(sol, usat, 0, -2);
}

int main () {
    cin >> n;
    paraulespro();
}