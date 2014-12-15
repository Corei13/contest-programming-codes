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
long long dp[51][51][51];

int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    dp[0][0][0] = 1;
    dp[1][1][0] = 0;
    for ( int i = 1; i < 51; i++ ) {
        dp[1][1][i] = 1;
        dp[0][0][i] = 1;
    }

    for (int k = 1; k < 51; k += 1) {
        for (int n = k; n < 51; n += 1) {
            for (int m = 0; m < 51; m += 1) {
                dp[n][k][m] = 0;

                for (int i = 1; i <= min ( min(m, n), n - k + 1 ) ; i += 1) {
                    dp[n][k][m] += dp[n - i][k - 1][m];
                }
            }
        }
    }

    int N, M, K;

    while (cin >> N >> K >> M) {
        cout << dp[N][K][M] << '\n';
    }

    return 0;
}










