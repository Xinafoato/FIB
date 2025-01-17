#include <iostream>
#include <vector>
using namespace std;


void perm(vector<int>& sol, vector<bool>& used, vector<string>& words, int idx) {
    if(idx == sol.size()) {
        for(int i : sol) cout  << words[i];
        cout << endl;
    }
    else {
        for(int i = 0; i < words.size(); ++i) {
            if(!used[i] && (idx == 0 || words[sol[idx-1]].back() != words[i][0])) {
                used[i] = true;
                sol[idx] = i;
                perm(sol,used,words,idx+1);
                used[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(string& s : words) cin >> s;
    vector<int> sol(n);
    vector<bool> used(n, false);
    perm(sol, used, words, 0);
}