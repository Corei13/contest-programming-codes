#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits>
#include <string>
#include <algorithm>
#include <set>



#define X first
#define Y second


using namespace std;


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int T, M, C, k[25], p[25][25];
    bool dp[250][25];
    cin >> T;

    for (int t = 0; t < T; t += 1) {
        cin >> M >> C;
        for (int i = 0; i < C; i += 1) {
            cin >> k[i];

            for (int j = 0; j < k[i]; j += 1) {
                cin >> p[i][j];
            }
        }

        dp[0][0] = true;
        for (int m = 1; m <= M; m += 1) {
            dp[m][0] = false;
        }

        for (int c = 1; c <= C; c += 1) {
            for (int m = 0; m <= M; m += 1) {
                dp[m][c] = false;
            }
            for (int m = 0; m <= M; m += 1) {
                for (int i = 0; i < k[c - 1]; i += 1) {
                    if ( m + p[c - 1][i] <= M && dp[m][c - 1] )   dp[m + p[c - 1][i]][c] = true;
                }
            }
        }

        for (int m = M; m >= 0; m -= 1) {
            if (dp[m][C]) {
                cout << m << '\n';
                goto HELL;
            }
        }
        cout << "no solution\n";
HELL:;
    }

    return 0;
}















