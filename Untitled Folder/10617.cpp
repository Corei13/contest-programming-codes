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

int T, N, W[105], Tot;
long long dp[61][61][61];

int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    for (int i = 0; i < 61; i += 1) {
        dp[i][0][0] = 1;
        for (int k = 2; k < 61; k += 1) {
            dp[i][0][k] = 0;
            dp[i][1][k] = 0;
        }
        dp[i][0][1] = 0;
    }
    for (int l = 0; l < 61; l += 1) {
        for (int i = 0; i < 61; i += 1) {
            dp[i][l][0] = 1;
        }
    }
    for (int i = 0; i < 61; i += 1) {
        for (int l = 0; l < 61; l += 1) {
            dp[i][l][1] = l;
        }
    }

    int T, N;
    long long A;
    string S;
    cin >> T;

    for ( int t = 0; t < T; t++ ) {
        cin >> S;
        N = S.size();

        for (int k = 2; k <= N; k += 1) {
            for (int l = k; l <= N; l += 1) {
                for (int i = 0; i < N; i += 1) {
                    dp[i][l][k] = 0;

                    if ( l >= k - 1 ) dp[i][l][k] += dp[i][l - 1][k];
                    if ( l >= k - 1 ) dp[i][l][k] += dp[i + 1][l - 1][k];
                    if ( l >= k - 2 ) dp[i][l][k] -= dp[i + 1][l - 2][k];

                    if ( S[i] == S[i + l - 1] ) {
                        dp[i][l][k] += dp[i + 1][l - 2][k - 2];
                    }
                }
            }
        }
        A = 0;
        for (int l = 1; l <= N; l += 1) {
            A += dp[0][N][l];
        }
        cout << A << '\n';
    }

    return 0;
}










