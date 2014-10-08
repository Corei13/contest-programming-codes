#include <bits/stdc++.h>

using namespace std;

#define a first
#define b second
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
typedef pair<double, double> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

vector<pair<int,PI>> disc;
VPI cont;

double findMax (double W) {
    int n = sz(cont) - 1;
    cout << W << ": ";
    VD w(n, 0.0);
    double ib = 0.0, limit, dW;
    for (int i = 0; i < n; ++i) {
        ib += 1.0 / (2.0 * cont[i].b);
        limit = (cont[i].a - cont[i+1].a) * ib;
        dW = min(W, limit);
        for (int j = 0; j <= i; ++j) {
            w[j] += dW / (2.0 * cont[j].b * ib);
        }
        W -= dW;
    }
    double ret = 0.0;
    for (int i = 0; i < n; ++i) {
        ret += cont[i].a * w[i] - cont[i].b * w[i] * w[i];
        cout << w[i] << ' ';
    }
    cout << " -> value = " << ret << endl;
    return ret;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int d;
    int W;
    while (cin >> d >> W) {
        disc.clear();
        cont.clear();
        for (int i = 0; i < d; ++i) {
            char type;
            cin >> type;
            if (type == 'D') {
                int w;
                double a, b;
                cin >> w >> a >> b;
                disc.push_back(mp(w, mp(a, b)));
            } else {
                double a, b;
                cin >> a >> b;
                cont.push_back(make_pair(a, (b + 1e-15) / 2.0));
            }
        }
        cont.push_back(make_pair(-inf, 0.0));
        sort(all(cont), greater<PI>());
        double ans = 0.0;
        VD dp(W + 1, -inf);
        dp[W] = 0.0;
        for (auto d: disc) {
            for (int w =  W; w > 0; w--) {
                for (int i = 0; d.a * i <= w; ++i) {
                    dp[W]
                }
            }
        }
    }
    
    return 0;
}