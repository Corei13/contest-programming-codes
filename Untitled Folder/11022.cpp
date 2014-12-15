#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits>
#include <string>
#include <algorithm>


#define X first
#define Y second


using namespace std;


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int L, tmp;
    int dp[200][200];
    string S, sub[200][200];

    while (cin >> S && S != "*") {
        L = S.size();
        for (int i = 0; i < L; i += 1) {
            sub[i][0] = "";
        }
        for (int i = 0; i < L; i += 1) {
            for (int l = 1; i + l <= L; l += 1) {
                sub[i][l] = sub[i][l - 1] + S[i + l - 1];
            }
        }
        for (int i = 0; i < L; i += 1) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for (int l = 2; l <= L; l += 1) {
            for (int i = 0; i + l <= L; i += 1) {
                dp[i][l] = l;
                for (int k = 1; k < l; k += 1) {
                    int occ = 1;
                    while (i + (occ * k + k) <= L && occ * k + k <= l && sub[i][k] == sub[i + occ * k][k]) {
                        occ++;
                    }
                    for (int j = 0; j < occ; j++)
                        dp[i][l] = min(dp[i][l], dp[i][k] + dp[i + (j + 1) * k][l - (j + 1) * k]);
                    //cout << sub[i][k] << ' ' << sub[i+k][min(k,l-k)] << ' ' << i << ' ' << l << ' ' << dp[i][l] << '\n';
                }
            }
        }
        cout << dp[0][L] << '\n';
    }

    return 0;
}















