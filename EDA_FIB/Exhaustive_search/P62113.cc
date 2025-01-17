#include <iostream>
#include <vector>
using namespace std;

int target;

void canvi(vector<int>& t, vector<int>& sol, vector<pair<int,int>>& usat, int idx, int sum) {
    if (sum == target) {
        cout << target << " = ";
        for (int i = 0; i < sol.size(); ++i) {
            if (i == sol.size()-1) cout << sol[i];
            else cout << sol[i] << " + ";
        }
    }
    else {
        for (int i = 0; i < t.size(); ++i) {
            if (usat[t[i]].second > 0) {
                sol[idx] = t[i];
            }
        }
    }
}
