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
typedef vector <long double> VD;
typedef vector <VD> VVD;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n;
        cin >> n;
        VVI grid(n, VI(n));
        for (auto &row: grid) for (auto &cell: row) {
            cin >> cell;
        }
        VVI dp(n + 1, VI((1 << n), 1000 * n * n));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int mask = 0; mask < (1 << n); ++mask) {
                for (int j = 0; j < n; ++j) if (mask & (1 << j)) {
                    dp[i][mask] = min(dp[i][mask], dp[i-1][mask ^ (1 << j)] + grid[i-1][j]);
                }
            }
        }
        cout << dp[n].back() << endl;
    }
    
    return 0;
}
