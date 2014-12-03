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

struct Solver {
    int n;
    vector <ll> a;
    string b;
    vector <vector <ll>> max, min;

    Solver (int n): n(n), a(n + 1), b(n, '?'),
        max(n + 1, vector <ll> (n + 1, numeric_limits <ll>::min())),
        min(n + 1, vector <ll> (n + 1, numeric_limits <ll>::max())) {}

    inline void update (int i, int j, ll res) {
        min[i][j] = std::min(min[i][j], res);
        max[i][j] = std::max(max[i][j], res);
    }

    inline void update (int i, int j, ll lhs, ll rhs, char op) {
        if (op == '?') {
            update (i, j, lhs, rhs, '+');
            update (i, j, lhs, rhs, '-');
            update (i, j, lhs, rhs, '*');
        } else {
            ll res;
            if (op == '+') {
                res = lhs + rhs;
            } else if (op == '-') {
                res = lhs - rhs;
            } else if (op == '*') {
                res = lhs * rhs;
            }
            update(i, j, res);
        }
    }

    void build (int len) {
        for (int l = 0; l <= len; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                int j = i + l;
                if (i == j) {
                    update(i, j, a[i]);
                } else {
                    for (int k = i; k < j; ++k) {
                        update (i, j,  min[i][k],  min[k + 1][j], b[k]);
                        update (i, j,  min[i][k],  max[k + 1][j], b[k]);
                        update (i, j,  max[i][k],  min[k + 1][j], b[k]);
                        update (i, j,  max[i][k],  max[k + 1][j], b[k]);
                    }
                }
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n;
    Solver *S;
    while (cin >> n) {
        VL a(n);
        string b(n, '?');
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        S = new Solver (2 * (n - 1));
        for (int i = 0; i < n - 1; ++i) {
            a.push_back(a[i]);
            b.push_back(b[i]);
        }
        b.pop_back();
        copy(a.begin(), a.end(), S->a.begin());
        copy(b.begin(), b.end(), S->b.begin());
        S->build(n - 1);
        for (int i = 0; i < n; ++i) {
            cout << abs(S->min[i][i + n - 1]) << abs(S->max[i][i + n - 1]);
        }
        cout << endl;
    }
    return 0;
}