#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>

#define X first
#define Y second


using namespace std;


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int N, M, d[205][20][20];
    long long A, dp[205][20];
    string CaseName;
    memset (dp[0], 0, sizeof(dp[0]));

    while (cin >> CaseName) {
        cin >> N >> M;
        for (int i = 0; i < N - 1; i += 1) {
            for (int j = 0; j < M; j += 1) {
                for (int k = 0; k < M; k += 1) {
                    cin >> d[i][j][k];
                }
            }
        }

        for (int n = 1; n < N; n += 1) {
            for (int m = 0; m < M; m += 1) {
                dp[n][m] = 100000000000000LL;
                for (int i = 0; i < M; i += 1) {
                    dp[n][m] = min(dp[n][m], dp[n - 1][i] + d[n - 1][i][m]);
                }
            }
        }
        A = 100000000000000LL;
        for (int i = 0; i < M; i += 1) {
            A = min(A, dp[N - 1][i]);
        }
        cout << CaseName << '\n' << A + 2 * (N - 1) << '\n';
    }

    return 0;
}















