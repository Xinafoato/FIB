#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;
typedef map<string, vector<string>> Graf;


// Ordenación topológica
void ordenacio_topologica(Graf& g, vector<string>& resultado, bool & b) {
    int n = g.size();
    map<string, int> grau;

    //inicialitcem els graus
    for(const auto& it : g) {
        for(const auto& neighbor : it.second) {
            ++grau[neighbor];
        }
    }   

    priority_queue <string, vector<string>, greater<string>> gzero;
    for(const auto& it : grau){
        if (it.second == 0){
            gzero.push(it.first);
        }
    }

    while(!gzero.empty()){
        string u = gzero.top();
        gzero.pop();
        resultado.push_back(u);
        cout << u << endl;
        for(int i = 0; i < g[u].size(); ++i) {
            string v = g[u][i];
            if(--grau[v] == 0){
                gzero.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n) {
        Graf g;
        string s;
        for(int i = 0; i < n; ++i) {
            cin >> s;
            g[s]; 
        }
        cin >> m;
        for(int i = 0; i < m; ++i){
            string aux1, aux2;
            cin >> aux1 >> aux2;
            g[aux1].push_back(aux2);
        }
        bool b = true;
        vector<string> resultado;
        ordenacio_topologica(g, resultado, b);



        for(int i = 0; i < resultado.size(); ++i) {
            cout << resultado[i] << ' ';
        }cout << endl;
    }
}
