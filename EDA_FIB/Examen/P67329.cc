#include <iostream>
#include <vector>
using namespace std;

int n;
vector<char> letters {'A', 'C', 'G', 'T'};

void permutacions (vector<int>& sol, int idx) {
    if (idx == sol.size()) {
        for(int i : sol) {
            cout << letters[i];
        }cout << endl;
    }
    else {
        for(int i = 0; i < letters.size(); ++i) {
            sol[idx] = i;
            permutacions(sol, idx+1);
        }
    }
}

int main () {
    cin >> n;
    vector<int> sol(n);
    permutacions(sol, 0);
}