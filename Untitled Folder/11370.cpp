#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>

#define X first
#define Y second


using namespace std;
double dp[250][250], I[250][250], x[250];

int main (int argc, char const *argv[]) {

    int T, N, K;

    scanf("%d", &T);

    for (int t = 0; t < T; t += 1) {
        scanf("%d %d", &N, &K);

        for (int i = 0; i < N; i += 1) {
            scanf("%lf", &x[i]);
        }

        for (int i = 0; i < N; i += 1) {
            for (int j = i + 1; j < N; j += 1) {
                I[i][j] = 0;

                for (int k = i + 1; k < j; k += 1) {
                    I[i][j] += fabs ( x[i] + ((x[j] - x[i]) * (k - i)) / double(j - i) - x[k] );
                }
            }
        }

        for (int i = 1; i < N; i += 1) {
            dp[i][2] = I[0][i];
        }

        for (int c = 3; c <= K; c += 1) {
            for (int M = c - 1; M < N; M += 1) {
                dp[M][c] = 1e9;

                for (int m = c - 2; m < M; m += 1) {
                    dp[M][c] = min ( dp[M][c], dp[m][c - 1] + I[m][M] );
                }
            }
        }

        printf("%.4lf\n", dp[N - 1][K] / double(N));
    }



    return 0;
}















