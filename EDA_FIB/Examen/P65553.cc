#include <iostream>
#include <map>
using namespace std;

void addg(const string& game, map<string, int>& m) {
    ++m[game];
}

bool canBuy(const string& game, map<string, int>& m, int totalGames) {
    return (m[game]+1 <= totalGames - m[game]);
}


int main() {
    int n, j;
    while(cin >> n) {
        map<string,int> m;
        string game;
        int totalgames = 0;
        for(int i = 0; i < n; ++i) {
            cin >> game;
            ++m[game];
            ++totalgames;
        }
        cin >> j;
        for(int i = 0; i < j; ++i) {
            cin >> game;
            if(canBuy(game, m, totalgames)) {
                ++m[game];
                ++totalgames;
            }
        }

        for(auto&i : m) {
            cout << i.first << ' ' << i.second << endl;
        }
        cout << string(20,'-') << endl;
    }
}