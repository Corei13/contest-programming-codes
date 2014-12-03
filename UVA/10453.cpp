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

    string s;
    while (cin >> s) {
        int n = sz(s);
        VVI dp(n + 1, VI(n + 1, 0));

        for (int l = 1; l <= n; ++l) {
            for (int i = 0, j = l; j <= n; ++i, ++j) {
                dp[i][j] = s[i] == s[j - 1] ? dp[i + 1][j - 1] : min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }

        string head, tail;

        for (int i = 0, j = n; i < j;) {
            if (s[i] == s[j - 1]) {
                head += s[i];
                if (i != j - 1) {
                    tail += s[j - 1];
                }
                i++, j--;
            } else if (dp[i][j] == dp[i + 1][j] + 1) {
                head += s[i];
                tail += s[i];
                i++;
            } else {
                head += s[j - 1];
                tail += s[j - 1];
                j--;
            }
        }
        reverse(all(tail));

        cout << dp[0][n] << ' ' << head + tail << endl;
    }

    return 0;
}