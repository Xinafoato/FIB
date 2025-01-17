#include <iostream>
#include <vector>
using namespace std;

void rec(vector<char>& sol, int idx, int a, int b) {
    if(idx == sol.size()) {
        for(auto i : sol) cout << i;
        cout << endl;
    }
    else {
        if(abs((a+1)-b) <= 2) {
            sol[idx] = 'a';
            rec(sol, idx+1, a+1, b);
        }
        if(abs(a-(b+1)) <= 2) {
            sol[idx] = 'b';
            rec(sol, idx+1, a, b+1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> sol(n);
    rec(sol, 0, 0,0);
}