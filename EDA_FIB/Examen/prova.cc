#include <iostream>
#include <vector>
using namespace std;

vector<int> centims{50,20,10,5,2,1};
int n;

void retor(vector<int>&sol, int sum) {
    if (sum > n) return;
    if(sum == n) {
        for(int i : sol) {
            cout << i << ' ';
        }cout << endl;
    }
    else {
        for(int i : centims) {
            if(sol.size() == 0 || sol.back() >= i) {
                sol.push_back(i);
                retor(sol, sum+i);
                sol.pop_back();
            }
        }
    }
}

int main() {
    cin >> n;
    vector<int> sol;
    retor(sol, 0);
}