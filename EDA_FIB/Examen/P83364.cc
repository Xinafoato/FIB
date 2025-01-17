#include <iostream>
#include <vector>
using namespace std;


void prefix (vector<int>& divisors, int idx, int actual, int n) {
    if (idx == n) {
        cout << actual << endl;
    }
    else {
        for (int i = 0; i <= 9; ++i) {
            int sig = actual*10 + i;
            bool divisible = false;
            for(int d = 0; !divisible && d < divisors.size(); ++d) {
                divisible = (sig%divisors[d] == 0);
            }

            if (!divisible) {
                prefix(divisors, idx+1, sig, n);
            }
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector<int> divisors(m);
        for(int d = 0; d < m;  ++d) cin >> divisors[d];
        prefix(divisors, 0, 0, n);
        
        cout << string(10, '-') << endl;
    }
    
}