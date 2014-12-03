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

typedef vector <long double> VD;
typedef vector <VD> VVD;


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        VL a(n + 1);
        for (auto& c : a) {
            cin >> c;
        }
        reverse(all(a));
        long double d, k, r;
        cin >> d >> k;
        r = 2.0 * k / d;
        ll m = ceil(-0.5 + sqrt(0.25 + r));
        ll ans = 0;
        for (auto c : a) {
            ans *= m;
            ans += c;
        }
        cout << ans << endl;
    }

    return 0;
}