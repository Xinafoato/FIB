#include <iostream>
#include <map>
using namespace std;


int main() {
  map<string, int> M;
  char c;
  while (cin >> c) {
    if (c == 'N') {
      cout << "number: " << M.size() << endl;
    }
    else if (c == 'D') {
      string nif;
      int money;
      cin >> nif >> money;
      M[nif] += money;
    }
    else if (c == 'Q') {
      string nif;
      cin >> nif;
      
      if(M.find(nif) == M.end()) cout << -1 << endl;
      else cout << M[nif] << endl;
    }
    else if (c == 'P') {
      bool primer = true;
      for(auto i : M) {
        if ((i.first[7] - '0')%2 == 0) {
          if(primer) primer = false;
          else cout << ' ';
          cout << i.first;
        }
      }cout << endl;
    }
    else { // c == 'L'
      if(M.size() < 1) cout << "NO LAST NIF" << endl;
      else {
        auto it = M.end();
        --it;
        cout << it->first << ' ' << it->second << endl;
      }

    }
  }
}
