#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>

#define X first
#define Y second


using namespace std;

int N, K, T, dp[5005][1200], a[5000];

int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    cin >> T;

    for (int t = 0; t < T; t += 1) {
        cin >> K >> N;
        K += 8;
        for (int i = 0; i < N; i += 1) {
            cin >> a[N - 1 - i];
        }

        for (int k = 0; k <= K; k += 1) {
            dp[0][k] = 100000000;
        }
        dp[0][0] = 0;
        for (int n = 1; n <= N; n += 1) {
            for (int k = 0; k <= K; k += 1) {
                dp[n][k] = 100000000;
            }
            for (int k = 0; k <= min(K, n / 3); k += 1) {
                dp[n][k] = dp[n - 1][k];

                if (n > 1 && n - 2 > 3 * (k - 1))  dp[n][k] = min(dp[n][k], (a[n - 1] - a[n - 2]) * (a[n - 1] - a[n - 2]) + dp[n - 2][k - 1]);

            }
        }
        cout << dp[N][K] << '\n';
    }


    return 0;
}















