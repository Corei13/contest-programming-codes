/*
    Knuth Optimization
*/

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int inf = 200000000;
    int n;
    while (cin >> n) {
        VI s(n + 1, 0);
        VVI dp(n + 2, VI(n + 2, 0)), r(n + 1, VI(n + 1));
        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
            s[i] += s[i - 1];
        }

        for (int i = 1; i <= n; ++i) {
            r[i][i] = i;
        }

        for (int l = 2; l <= n; ++l) {
            for (int i = 1, j = l; j <= n; ++i, ++j) {
                dp[i][j] = inf;
                for (int k = r[i][j - 1]; k <= r[i + 1][j]; ++k) {
                    if (dp[i][k - 1] + dp[k + 1][j] + (s[j] - s[k]) + (s[k - 1] - s[i - 1]) < dp[i][j]) {
                        dp[i][j] = dp[i][k - 1] + dp[k + 1][j] + (s[j] - s[k]) + (s[k - 1] - s[i - 1]);
                        r[i][j] = k;
                    }
                }
            }
        }

        cout << dp[1][n] << endl;
    }

    return 0;
}