#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>


#define X first
#define Y second


using namespace std;
int LCS( string X, string Y, int m, int n ) {
    int C[m + 1][n + 1];

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
            } else    C[i][j] = max( C[i - 1][j], C[i][j - 1] );
        }
    }

    return C[m][n];
}


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int N, M;
    string S, T;
    int t = 0;

    while ( getline(cin, S) && S[0] != '#' ) {
        getline(cin, T);
        cout << "Case #" << ++t << ": you can visit at most " << LCS(S, T, S.size(), T.size()) << " cities.\n";
    }

    return 0;
}















