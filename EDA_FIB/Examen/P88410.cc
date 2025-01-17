#include <iostream>
#include <vector>
using namespace std;

void color(vector<int>& sol, vector<int>& qroses, int n, int idx, int ant, bool parella) {
    if (idx == n*3 && parella) {
        for(int i : sol) cout << i;
        cout << endl;
    }

    else {
        for (int i = 1; i <= 3; ++i) {
            if(qroses[i] > 0 && (!parella || i != ant)) {
                sol[idx] = i;
                --qroses[i];
                color(sol, qroses, n, idx+1, i, parella ||i == ant);
                ++qroses[i];
            }
        }
    }
}

void colors(int n) {
    vector<int> sol(n*3);
    vector<int> qroses(4,n);
    color(sol, qroses, n, 0, 0, false);
}

int main(){
    int n;
    while (cin >> n) {
        colors(n);
        cout << string(10,'*') << endl;
    }
}