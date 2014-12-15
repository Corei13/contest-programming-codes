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


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    long long dp[205][15][25], a[205], b[205];
    int N, Q, D, M, t = 0;

    while ( cin >> N >> Q && (N + Q) ) {
        cout << "SET " << ++t << ":\n";
        for (int i = 0; i < N; i += 1) {
            cin >> a[i];
        }

        for (int q = 1; q <= Q; q += 1) {
            cin >> D >> M;
            for (int i = 0; i < N; i += 1) {
                b[i] = a[i] % D;
                b[i] = (b[i] + D) % D;
            }

            for (int n = 0; n <= N; n += 1) {
                dp[n][0][0] = 1;

                for (int m = 1; m <= min(n, M); m += 1) {
                    for (int s = 0; s < D; s += 1) {
                        dp[n][m][s] = dp[n - 1][m - 1][(s - b[n - 1] + D) % D];
                        if (n - 1 >= m)    dp[n][m][s] += dp[n - 1][m][s];
                    }
                }
            }
            cout << "QUERY " << q << ": " << dp[N][M][0] << '\n';
        }
    }

    return 0;
}















