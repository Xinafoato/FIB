#include <iostream>
#include <vector>
using namespace std;


int first_occurrence(double x, const vector<double>& v, int l, int r) {
    if (l > r) return -1;
    else {
        int m = (l+r)/2;
        if (v[m] == x){
            int aux = first_occurrence(x, v, l, m-1);
            if(aux == -1) return m;
            else return aux;
        }
        else if (v[m] > x) {
            int aux = first_occurrence(x, v, l, m-1);
            if (aux == -1) {
                if (m+1 <= r && v[m+1] == x) return m+1;
                else return -1;
            }
            else return aux;
        }
        else {
            if(m-1 >= l && v[m-1] == x) return m-1;
            return first_occurrence(x, v, m+1, r);
        }
    }
}

int first_occurrence(double x, const vector<double>& v) {
    return first_occurrence(x, v, 0, v.size()-1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
