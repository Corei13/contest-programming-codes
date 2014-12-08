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

string LCS( string X[], string Y[], int m, int n ) {
    pair <int, string> C[m + 1][n + 1];

    for (int i = 0; i <= m; i += 1) {
        C[i][0].X = 0;
        C[i][0].Y = "";
    }
    for (int i = 0; i <= n; i += 1) {
        C[0][i].X = 0;
        C[0][i].Y = "";
    }

    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            if (X[i - 1] == Y[j - 1]) {
                C[i][j] = make_pair ( C[i - 1][j - 1].X + 1, C[i - 1][j - 1].Y + (C[i - 1][j - 1].X ? " " : "") + X[i - 1] );
            } else    C[i][j] = ( C[i - 1][j].X > C[i][j - 1].X ) ? C[i - 1][j] : C[i][j - 1];
        }
    }

    return C[m][n].Y;
}


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int N, M;
    string S, X[10000], Y[10000];
    int x, y;

    while ( cin >> S ) {
        x = 0;
        y = 0;
        while (S != "#") {
            X[x++] = S;
            cin >> S;
        }
        cin >> S;
        while (S != "#") {
            Y[y++] = S;
            cin >> S;
        }
        cout << LCS(X, Y, x, y) << '\n';
    }

    return 0;
}















