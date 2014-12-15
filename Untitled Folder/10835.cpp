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

int hash ( string S, int L ) { // HTTHHT = 100110
    int ret = 0;
    for (int i = L - 1; i >= 0; i -= 1) {
        ret += ( (S[i] == 'H' ) << (L - 1 - i ) );
    }
    return ret;
}

long long p2[55];

long long gcd ( long long a, long long b ) {
    if (a) {
        return gcd(b % a, a);
    } else    return b;
}

int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int N, P, L;
    long long dp[60][2048], t = 0;
    bool bad[2048];
    string S;

    p2[0] = 1;
    for (int i = 1; i < 55; i += 1) {
        p2[i] = p2[i - 1] << 1;
    }

    while (cin >> N >> P && (N + P)) {
        cout << "Case " << ++t << ": ";
        if (P == 0) {
            cout << "1/1" << '\n';
            continue;
        }
        cin >> S;
        L = S.size();
        for (int i = 0; i < (1 << L); i += 1) {
            bad[i] = false;
            for (int j = 0; j <= N; j += 1) {
                dp[j][i] = 0;
            }
        }
        bad[hash(S, L)] = true;
        for (int i = 1; i < P; i += 1) {
            cin >> S;
            bad[hash(S, L)] = true;
        }

        for (int i = 0; i < (1 << (L - 1)); i += 1) {
            dp[L - 1][i] = 1;
        }

        for (int n = L; n <= N; n += 1) {
            for (int i = 0; i < (1 << (L - 1)); i += 1) {
                if (!bad[(1 << (L - 1)) + i])  dp[n][(1 << (L - 2)) + (i >> 1)] += dp[n - 1][i];
                if (!bad[i])     dp[n][(i >> 1)] += dp[n - 1][i];
            }
        }
        long long Ans = 0;
        for (int i = 0; i < (1 << (L - 1)); i += 1) {
            Ans += dp[N][i];
        }
        long long g = gcd(Ans, p2[N]);
        if (L > N) {
            cout << "1/1" << '\n';
        } else if (Ans)    cout << Ans / g << '/' << p2[N] / g << '\n';
        else    cout << 0 << '\n';
    }

    return 0;
}















