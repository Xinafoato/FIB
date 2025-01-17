#include <iostream>
#include <vector>
using namespace std;


int n;

void cons_vocal(vector<bool>& convob, vector<char>& convoi, vector<char>& sol, bool ant, int idx) {
    if (idx == 2*n) {
        for(int i = 1; i <= sol.size(); ++i) {
            cout << sol[i];
        } cout << endl;
    }
    else {
        for (int i = 1; i <= 2*n; ++i) {
            if(ant and not convob[2 * i]) {   //anterior consonant i no visitat
                sol[idx] = convoi[2*i];
                convob[2*i] = true;
                cons_vocal(convob, convoi, sol, false, idx+1);
                convob[2*i] = false;
            }
            else if(not ant and not convob[i]) {   //anterior vocal i no visitat
                sol[idx] = convoi[i];
                convob[i] = true;
                ant = true;
                cons_vocal(convob, convoi, sol, false, idx+1);
                convob[i] = false;
            }

        }
    }
}

void cons_vocals(vector<char>& convoi) {
    vector<bool> convob(2*n, false);
    vector<char> sol(2*n);
    bool ant = true;
    cons_vocal(convob, convoi, sol, ant, 0);
}

int main() {
    cin >> n;
    vector<char> convoi(2*n); // 1 a n consonantes de n+1 a 2*n vocales
    for(int i = 1; i <= 2*n; ++i) {
        cin >> convoi[i];          
    }
    cons_vocals(convoi);
}