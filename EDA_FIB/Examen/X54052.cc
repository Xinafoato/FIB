#include <iostream>
#include <vector>
using namespace std;

vector<char> posibiliy = {'A', 'C', 'G', 'T'};

char inv (char c) {
    if(c == 'A') return 'T';
    if(c == 'T') return 'A';
    if(c == 'C') return 'G';
    else         return 'C';
}

void adn(vector<char>& A, vector<char>& B, int idx) {
    int n = A.size();
    if (idx == n) {
        for(char c: A) cout << c;
        cout << endl;
        for(char c: B) cout << c;
        cout << endl;
        cout << endl;
    }
    else{
        if (A[idx] != '.' && B[idx] != '.' && inv(A[idx]) != B[idx]) return;
        else if (A[idx] == '.' && B[idx] == '.') {
            for(char c : posibiliy) {
                A[idx] = c;
                B[idx] = inv(c);
                adn(A, B, idx+1);
                A[idx] = B[idx] = '.';
            }
        }
        else if(A[idx] != '.') {
            char ant = B[idx];
            B[idx] = inv(A[idx]);
            adn(A, B, idx+1);
            B[idx] = ant;
        }
        else {        // B[idx] != '.'
            char ant = A[idx];
            A[idx] = inv(B[idx]);
            adn(A, B, idx+1);
            A[idx] = ant;
        }
        
    }
}

int main() {
    int n;
    while(cin >> n) {
        vector<char> A(n);
        vector<char> B(n);
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];

        adn(A, B, 0);
        cout << string(10, '-') << endl;
    }
}