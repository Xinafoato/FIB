#include <iostream>
#include <vector>
using namespace std;

void opera(vector<char>&sol, int idx, int c, int a) {
    if(idx == sol.size()) {
        for(char i : sol) cout << i;
        cout << endl;
    }
    else {
        if (c != 0) {
            sol[idx] = 'b';
            opera(sol, idx+1, c-1, a+1);
        }

        if (a != 0) {
            sol[idx] = 's';
            opera(sol, idx+1, c+1, a-1);
        }

    }
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<char> sol(n);
    opera(sol, 0, c, 0);
}