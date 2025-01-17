#include <iostream>
#include <vector>

using namespace std;

bool reachable(vector<vector<char> >& M, int f, int c) {
	if(f < 0 or c < 0 or f >= M.size() or c >= M[0].size() or M[f][c] == 'X') return false;
	
	if (M[f][c] == 't') return true;
	M[f][c] = 'X'; 

	return reachable(M, f+1,c) or reachable(M, f-1,c) or reachable(M, f,c+1) or reachable(M, f,c-1);
}

int main() {
	int n, m, f, c;
	cin >> n >> m;
	
	vector<vector<char> > M(n, vector<char>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j) cin >> M[i][j];
	
    }
	cin >> f >> c;

	if (reachable(M,f - 1,c - 1)) cout << "yes" << endl;
	else cout << "no" << endl;
}