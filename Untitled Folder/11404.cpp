#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <limits>

using namespace std;

#define X first
#define Y second

using namespace std;

int N;
string S, T;

int C[1006][1006];
vector <string> v;
int LCS( string X, string Y, int m, int n, int L = 0 ) {
    for (int i = 0; i <= m; i += 1) {
        C[i][0] = 0;
    }
    for (int i = 0; i <= n; i += 1) {
        C[0][i] = 0;
    }

    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            if (X[i - 1] == Y[j - 1]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                if (L && C[i][j] == L) {
                    v.push_back
                }
            } else    C[i][j] = max( C[i - 1][j], C[i][j - 1] );
        }
    }

    return C[m][n];
}


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    while ( cin >> S ) {
        N = S.size();
        T = "";

        for (int i = 0; i < N; i += 1) {
            T += S[N - 1 - i];
        }
        cout << LCS(S, T, N, N) << '\n';
    }

    return 0;
}










