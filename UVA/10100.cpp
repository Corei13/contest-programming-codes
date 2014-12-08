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
int LCS( string X[], string Y[], int m, int n ) {
    int C[m + 1][n + 1];

    while (m > 0 && X[m - 1] == "") {
        --m;
    }
    while (n > 0 && Y[n - 1] == "") {
        --n;
    }

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

bool isChar ( char c ) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
}

int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int N, M, Size, ans;
    string a[1005], b[1005];
    string s;
    int t = 0;

    while ( getline(cin, s) ) {

        N = 0;
        if (s.size() == 0) {
            printf("%2d. Blank!\n", ++t);
            getline(cin, s);
            continue;
        }
        Size = s.size();
        for (int i = 0; i < Size; i += 1) {
            if (!isChar(s[i])) {
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        while (ss >> a[N++]) {
            /*cout << a[N-1] << '\n';*/
        }

        getline(cin, s);
        M = 0;
        if (s.size() == 0) {
            printf("%2d. Blank!\n", ++t);
            continue;
        }
        Size = s.size();
        for (int i = 0; i < Size; i += 1) {
            if (!isChar(s[i])) {
                s[i] = ' ';
            }
        }
        stringstream st(s);
        while (st >> b[M++]) {
            /*cout << b[M-1] << '\n';*/
        }
        ans = LCS(a, b, N, M);
        printf("%2d. Length of longest match: %d\n", ++t, ans);

    }

    return 0;
}















