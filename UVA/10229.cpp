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
typedef pair<int, ll> PI;
typedef vector<PI> VPI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

VVL mul (VVL a, VVL b, ll mod) {
    return VVL {
        VL{(a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod, (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod},
        VL{(a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod, (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod}
    };
}

VVL fpow (VVL a, ll p, ll mod) {
    if (p == 0) {
        return VVL {VL {1, 0}, VL {0, 1}};
    } else {
        VVL ret = fpow(a, p / 2LL, mod);
        ret = mul (ret, ret, mod);
        if (p % 2LL == 1) {
            ret = mul (ret, a, mod);
        }
        return ret;
    }
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    ll n, m;
    while (cin >> n >> m) {
        ll mod = (1LL << m);
        if (n <= 1) {
            cout << n % mod << endl;
        } else {
            VVL a = fpow(VVL {VL {1, 1}, VL{1, 0}}, n - 1LL, mod);
            cout << a[0][0] << endl;
        }
    }


    return 0;
}