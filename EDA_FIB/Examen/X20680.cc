#include <iostream>
#include <vector>
using namespace std;

vector<char> lletres {'x', 'y', 'z'};

void permutacions(vector<int>& sol, vector<int>& cops, int idx, const int n, const int c) {
    if (idx == n) {
        for(int i : sol) {
            cout << lletres[i];
        }cout << endl;
    }
    else {
        for(int i = 0; i < 3; ++i) {
            if (cops[i] > 0) {
                sol[idx] = i;
                --cops[i];
                if(idx > 0 && sol[idx-1] != i) {
                    int ant = cops[sol[idx-1]];
                    cops[sol[idx-1]] = c;
                    permutacions(sol, cops, idx+1,n,c);
                    cops[sol[idx-1]] = ant;
                }
                else {
                    permutacions(sol, cops, idx+1, n, c);
                }
                ++cops[i];
            }
        }
    }
}

int main () {
    int n, c;
    while (cin >> n >> c) {
        vector<int> sol(n);
        vector<int> cops(3,c);
        permutacions(sol, cops, 0, n, c);
        cout << string(20, '-') << endl;
    }
}