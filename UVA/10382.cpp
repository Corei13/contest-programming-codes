#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

using namespace std;

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

    for (int n, l, w; cin >> n >> l >> w;) {
        vector <pair <double, double>> points;
        for (int i = 0; i < n; ++i) {
            double x, r;
            cin >> x >> r;
            if (r >= w / 2.0) {
                double d = sqrt (r * r - (w * w) / 4.0);
                points.push_back(make_pair(max(0.0, x - d), min (x + d, double(l))));
            }
        }
        sort (all(points));
        const double eps = 1e-9;
        double pos = 0.0;
        int ans = 0;
        for (int i = 0; i < n;) {
            double next = pos;
            while (i < n && points[i].x <= pos + eps) {
                next = max (next, points[i].y);
                i++;
            }
            if (next > pos) {
                pos = next;
                ans++;
            } else break;
        }
        if (pos < l - eps) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}