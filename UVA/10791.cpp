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

ll minSum (ll n) {
    if (n == 1) {
        return 2;
    }
    ll ret = 0, tot = 0;
    for (ll i = 2; i * i <= n; ++i) if(n % i == 0) {
        ll a = 1;
        while (n % i == 0) {
            a *= i;
            n /= i;
        }
        ret += a;
        tot += 1;
    }
    if (n != 1) {
        ret += n;
        tot += 1;
    }
    if (tot == 1) {
        return ret + 1;
    } else {
        return ret;
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int n, cs = 0;
    while (cin >> n && n != 0) {
        cout << "Case " << ++cs << ": " << minSum(n) << endl;
    }
    return 0;
}