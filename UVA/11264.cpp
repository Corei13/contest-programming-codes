#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <ll, ll> PI;
typedef vector <PI> VPI;
typedef vector <VPI> VVPI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <string> VS;
typedef vector <bool> VB;
typedef vector <long double> VD;
typedef vector <VD> VVD;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    ll inf = 1000000000000000000LL;
    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n;
        cin >> n;
        VVL dp(n + 1, VL(32, inf));
        VL a(n + 1);
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        a[n] = 2LL * inf;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (int j = 1; j < 32; ++j) if (dp[i - 1][j - 1] < a[i - 1] && a[i - 1] + dp[i - 1][j - 1] < a[i]) {
                    dp[i][j] = min(dp[i][j], a[i - 1] + dp[i - 1][j - 1]);
                }
        }
        for (int i = 31; i >= 0; --i) if (dp[n][i] < inf) {
                cout << i << endl;
                break;
            }
    }

    return 0;
}
