#include <iostream>
#include <set>
using namespace std;

typedef long long int lint;

int main() {
    lint suma;
    set<lint> selec;
    set<lint> resta;

    lint n;
    cin >> n;
    string op;
    lint val;

    while (cin >> op >> val) {
        if (op == "deixar") {
            if (selec.size() < n) {
                selec.insert(val);
                suma += val;
            }
            else {
                lint min = *(selec.begin());
                if (min < val) {
                    selec.insert(val);
                    selec.erase(selec.begin());
                    suma = suma + val - min;
                    resta. insert(min);
                }
                else resta.insert(val);
            }
        }
        else { // endur
            if (*(selec.begin()) <= val) {
                selec.erase(val);
                suma -= val;
                if (resta.size() > 0) {
                    set<lint>::iterator it = resta.end();
                    --it;
                    selec.insert(*it);
                    suma += *it;
                    resta.erase(it);
                }
            }
            else resta.erase(val);
        }
        cout << suma << endl;
    }
}