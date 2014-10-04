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

    const ll mod = 10007;

    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        string a, b, c;
        cin >> a >> b >> c;
        VVVL dp[2] = {VVVL(c.size() + 1, VVL(a.size() + 1, VL(b.size() + 1, 0))), VVVL(c.size() + 1, VVL(a.size() + 1, VL(b.size() + 1, 0)))};
        dp[0][0] = VVL(a.size() + 1, VL(b.size() + 1, 0));
        dp[1][0] = VVL(a.size() + 1, VL(b.size() + 1, 1));
        for (int i = -1; i < sz(a); ++i) {
            for (int j = -1; j < sz(b); ++j) {
                for (int k = 0; k < sz(c); ++k) {
                    if (i >= 0) {
                        dp[0][k+1][i+1][j+1] = dp[0][k+1][i][j+1];
                        if (a[i] == c[k]) {
                            dp[0][k+1][i+1][j+1] += (dp[0][k][i][j+1] + dp[1][k][i][j+1]);
                        }
                    }
                    if (j >= 0) {
                        dp[1][k+1][i+1][j+1] = dp[1][k+1][i+1][j];
                        if (b[j] == c[k]) {
                            dp[1][k+1][i+1][j+1] += (dp[0][k][i+1][j] + dp[1][k][i+1][j]);
                        }
                    }

                    dp[0][k+1][i+1][j+1] %= mod;
                    dp[1][k+1][i+1][j+1] %= mod;
                }
            }
        }
        cout << (dp[0][c.size()][a.size()][b.size()] + dp[1][c.size()][a.size()][b.size()]) % mod << endl;
    }
    
    return 0;
}