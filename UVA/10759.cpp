#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()

typedef unsigned long long ll;
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

    VVL dp(25, VL(150, 0));
    VL p6(25);
    dp[0][0] = 1;
    p6[0] = 1;
    for (int n = 1; n <= 24; ++n) {
        p6[n] = 6LL * p6[n - 1];
        for (int i = n; i <= 6 * n; ++i) {
            for (int d = 1; d <= min(6, i); ++d) {
                dp[n][i] += dp[n - 1][i - d];
            }
        }
    }

    int n, k;
    while (cin >> n >> k && n != 0) {
        ll a = 0, b = p6[n];
        for (int i = k; i < 150; ++i) {
            a += dp[n][i];
        }
        if (a == b) {
            cout << 1 << endl;
        } else if (a == 0) {
            cout << 0 << endl;
        } else {
            cout << a / __gcd(a, b) << '/' << b / __gcd(a, b) << endl;
        }
    }

    return 0;
}
