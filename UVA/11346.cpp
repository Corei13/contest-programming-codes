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

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        double a, b, s, d, pr;
        cin >> a >> b >> s;
        d = s / (a * b);
        if (d < 1e-15) {
            pr = 1.0;
        } else if (d >= 1.0) {
            pr = 0.0;
        } else {
            pr = 1.0 - d * (1.0 - log(d));
        }
        cout << fixed << setprecision(6) << pr * 100.0 << "%" << endl;
    }
;
    return 0;
}