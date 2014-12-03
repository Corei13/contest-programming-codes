#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <set>
#include <map>
#include <deque>
#include <functional>

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

struct LIS {
    int n;
    VI a;

    LIS (int n): n(n), a(n) {}

    void buildLIS (int ord, VI& idx) {
        VPI best;
        idx = VI(n, 0);

        for (int i = 0; i < n; i++) {
            PI u = make_pair(a[i] * ord, i);
            auto it = upper_bound(all(best), u);

            if (it == best.end()) {
                if (best.empty()) {
                    idx[i] = 0;
                } else {
                    idx[i] = idx[best.back().y] + 1;
                }
                best.push_back(u);
            } else {
                idx[i] = idx[it->y];
                *it = u;
            }
        }
    }
};


int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        LIS L(n);
        VI inc, dec;

        for (int i = 0; i < n; ++i) {
            cin >> L.a[i];
        }
        reverse(all(L.a));
        L.buildLIS(+1, inc);

        L.buildLIS(-1, dec);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, inc[i] + dec[i] + 1);
        }
        cout << ans << endl;
    }

    return 0;
}