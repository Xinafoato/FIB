#include <iostream>
#include <vector>
using namespace std;

int c, f;

void torres(vector<int>&sol, vector<bool>& atacat, int idx) {
    if(idx == f) {
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                if(sol[i] == j) cout << 'R';
                else cout << '.';
            } cout << endl;
        } cout << endl;
    }
    else {
        for (int i = 0; i < c; ++i) {
            sol[idx] = i;
            if (!atacat[i]) {
                atacat[i] = true;
                torres(sol, atacat, idx+1);
                atacat[i] = false;
            }
        }
    }
}

void torres() {
    vector<int> sol(c);
    vector<bool> atacat(c, false);
    torres(sol,atacat, 0);
}

int main() {
    cin >> f >> c;
    torres();
}