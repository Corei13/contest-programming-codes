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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<ll, ll> PI;

int main(int argc, char const *argv[]) {
    ll M = 2000, million = 1000000LL;
    ll max_a = 125, max_ab = 20000, min_s = 600, min_c_plus_d = 350;
    VL Sqrt(M * M, -1);

    VVL div(max_ab + 1);
    for (ll d = 1; d * d <= max_ab; ++d) {
        for (int n = d * d; n <= max_ab; n += d) {
            div[n].push_back(d);
        }
    }
    
    VL mdiv;
    for (ll d = 1; d * d <= million; ++d) if (million % d == 0) {
        mdiv.push_back(d);
    }

    for (int i = 0; i < M; ++i) {
        Sqrt[i * i] = i;
    }

    for (ll s = min_s; s <= M; s+= 1 ) { // s = (a + b + c + d), a <= b <= c <= d
        ll abcd = s * million;
        set <ll> sdiv;
        for (auto ds: div[s]) {
            for (auto ms: mdiv) {
                ll l, r;
                l = ds, r = ms;
                if (s <= l * r && l * r <= abcd / (l * r)) {
                    sdiv.insert(l * r);
                }
                l = s / ds, r = ms;
                if (s <= l * r && l * r <= abcd / (l * r)) {
                    sdiv.insert(l * r);
                }
                l = ds, r = million / ms;
                if (s <= l * r && l * r <= abcd / (l * r)) {
                    sdiv.insert(l * r);
                }
                l = s / ds, r = million / ms;
                if (s <= l * r && l * r <= abcd / (l * r)) {
                    sdiv.insert(l * r);
                }
            }
        }
        for (ll ab: sdiv) if (ab > max_ab) break; else {
            ll cd = abcd / ab;
            for (ll a: div[ab]) if (a > max_a ) break; else if ( min_c_plus_d + a + ab / a <= s ) {
                ll b = ab / a;
                ll c_plus_d = s - a - b;
                if (c_plus_d * c_plus_d >= 4LL * cd && Sqrt[c_plus_d * c_plus_d - 4LL * cd] != -1) {
                    ll D = Sqrt[c_plus_d * c_plus_d - 4LL * cd];
                    ll c = (c_plus_d - D) / 2LL, d = (c_plus_d + D) / 2LL;
                    if (c >= b && c * d == cd && a <= M && b <= M && c <= M && d <= M) {
                        printf("%.2lf %.2lf %.2lf %.2lf\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
                    }
                }
            }
        }
    }
    return 0;
}