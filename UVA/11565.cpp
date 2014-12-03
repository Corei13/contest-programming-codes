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

bool check (ll x, ll y, ll z, ll a, ll c) {
    return x + y + z == a && x * x + y * y + z * z == c && x < y && y < z;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    VVL div (10000 + 1);
    for (int d = 1; d <= 10000; ++d) {
        for (int n = d * d; n <= 10000; n += d) {
            div[n].push_back(d);
        }
    }
    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        ll a, xyz, c;
        cin >> a >> xyz >> c;

        vector <pair <int, PI>> sol;
        for (auto x : div[xyz]) {
            ll yz = xyz / x;
            for (auto y : div[yz]) {
                ll z = yz / y;
                if (check (+x, +y, +z, a, c)) sol.pb (mp(+x, mp(+y, +z)));
                if (check (-x, -y, +z, a, c)) sol.pb (mp(-x, mp(-y, +z)));
                if (check (+x, -y, -z, a, c)) sol.pb (mp(+x, mp(-y, -z)));
                if (check (-x, +y, -z, a, c)) sol.pb (mp(-x, mp(+y, -z)));
            }
        }
        if (!sol.empty()) {
            sort(all(sol));
            cout << sol.front().x << ' ' << sol.front().y.x << ' ' << sol.front().y.y << endl;
        } else {
            cout << "No solution." << endl;
        }

    }

    return 0;
}
