#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            cout << "NO VALID ORDERING" << endl;
            continue;
        }

        vector<vector<int>> graf(n);
        map<string, int> pos;
        map<int, string> res;
        string s;

        // Llegir noms de les tasques
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            pos[s] = i;
            res[i] = s;
        }

        vector<int> inp_degree(n, 0);
        int m;
        cin >> m;

        // Llegir dependències
        for (int i = 0; i < m; ++i)
        {
            string s1, s2;
            cin >> s1 >> s2;
            int p1 = pos[s1];
            int p2 = pos[s2];
            graf[p1].push_back(p2);
            ++inp_degree[p2];
        }

        // Cua de prioritat per mantenir ordre lexicogràfic
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int j = 0; j < n; ++j)
        {
            if (inp_degree[j] == 0)
                heap.push(j);
        }

        // Ordenació topològica
        vector<int> ordre;
        while (!heap.empty())
        {
            int node = heap.top();
            heap.pop();
            ordre.push_back(node);
            for (int p : graf[node])
            {
                --inp_degree[p];
                if (inp_degree[p] == 0)
                    heap.push(p);
            }
        }

        // Verificar si hi ha un cicle
        if (ordre.size() < n)
        {
            cout << "NO VALID ORDERING" << endl;
            continue;
        }

        // Imprimir resultat
        for (int i = 0; i < ordre.size(); ++i)
        {
            cout << res[ordre[i]];
        }
        cout << endl;
    }
}