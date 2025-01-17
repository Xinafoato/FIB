#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n_canvis(const vector<int>& m, int idx, int x, int sumpar) {
    if (sumpar > x) return 0;
    if (idx == m.size ()) return 1;
    int cnt = 0;
    for (int v = 0; v <= 2; ++v)
    cnt += n_canvis(m, idx+1, x, sumpar + v*m[idx]);
    return cnt;
}

int main() {
    int x, n;
    while(cin >> x) {
        cin >> n;
        vector<int> coins;
        for(int i = 0; i <n; ++i) {
            int s;
            cin >> s;
            coins.push_back(s);
        }
        sort(coins.begin(), coins.end());

        cout << n_canvis(coins, 0, x, 0) << endl;
        
    
    }
}