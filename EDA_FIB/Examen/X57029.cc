#include <iostream>
#include <vector>
using namespace std;



void pmovs(vector<char>& sol, int idx, int altura) {
    if (idx == sol.size()) {
        for(auto i : sol) cout << i;
        cout << endl;
    }
    else {
        if(altura != 0) {
            sol[idx] = 'd';
            pmovs(sol, idx+1, altura-1);
        }

        sol[idx] = 'h';
        pmovs(sol, idx+1, altura);

        sol[idx] = 'u';
        pmovs(sol, idx+1, altura+1);

    }
}

int main() {
    int n;
    cin >> n;
    vector<char> sol(n);
    pmovs(sol, 0, 0);
}