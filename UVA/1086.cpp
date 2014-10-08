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
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int n, m, cs = 0;;
    while (cin >> n >> m && n != 0) {
        VVB closure(2 * n, VB(2 * n, false));
        #define neg(i) (i < n ? i + n : i - n)
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            VI a(k);
            for (auto &j: a) {
                char vote;
                cin >> j >> vote;
                j--;
                if (vote == 'n') {
                    j += n;
                }
            }
            if (k <= 2) {
                for (auto j: a) {
                    closure[neg(j)][j] = true;
                }
            } else {
                for (auto j: a) for (auto k: a) if (j != k) {
                    closure[neg(j)][k] = true;
                }
            }
        }
        for (int k = 0; k < 2 * n; ++k) {
            for (int i = 0; i < 2 * n; ++i) {
                for (int j = 0; j < 2 * n; ++j) {
                    closure[i][j] = closure[i][j] or (closure[i][k] and closure[k][j]);
                }
            }
        }
        bool possible = true;
        for (int i = 0; i < n; ++i) if (closure[i][i+n] and closure[i+n][i]) {
            possible = false;
        }
        cout << "Case " << ++cs << ": ";
        if (possible) {
            for (int i = 0; i < n; ++i) if (closure[i][i+n]) {
                cout << "n";
            } else if (closure[i+n][i]) {
                cout << "y";
            } else {
                cout << "?";
            }
            cout << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    
    return 0;
}