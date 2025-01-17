#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool vocal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void escriure(vector<char>& sol, vector<char>& entrada, int idx){
    if (idx == sol.size()) {
        for(char i : sol) {
            cout << i;
        }cout << endl;
    }
    else {
        for(char c: entrada) {
            if(!vocal(c) || idx == 0 || !vocal(sol[idx -1])) {
                sol[idx] = c;
                escriure(sol, entrada, idx+1);
            }
        }
    }
}

int main () {
    int n, m;
    while(cin >> n >> m) {
        vector<char> entrada(m);
        for(int i = 0; i < m; ++i) cin >> entrada[i];
        sort(entrada.begin(), entrada.end());

        vector<char> sol(n);
        escriure(sol, entrada, 0);
        cout << string(10, '-') << endl;
    }
}