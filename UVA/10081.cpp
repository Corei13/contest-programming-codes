#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>

#define X first
#define Y second


using namespace std;


int main (int argc, char const *argv[]) {
    //ios::sync_with_stdio(false);

    int N, K;
    double dp[105][15], tight;

    while (cin >> K >> N ) {
        ++K;
        for (int k = 0; k < K; k += 1) {
            dp[1][k] = 1.0 / double(K);
        }
        for (int n = 2; n <= N; n += 1) {
            for (int k = 0; k < K; k += 1) {
                dp[n][k] = 1.0 * dp[n - 1][k] / double(K);
                if ( k < K - 1 )   dp[n][k] += 1.0 * dp[n - 1][k + 1] / double(K);
                if ( k > 0 ) dp[n][k] += 1.0 * dp[n - 1][k - 1] / double(K);
            }
        }
        tight = 0;
        for (int i = 0; i < K; i += 1) {
            tight += dp[N][i];
        }
        tight *= 100.0;
        printf("%.5lf\n", tight);
    }

    return 0;
}















