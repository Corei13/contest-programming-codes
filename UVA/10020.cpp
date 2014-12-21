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

    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int l;
        cin >> l;
        vector <pair <int, int>> points;
        for (int l, r; cin >> l >> r && !(l == 0 && r == 0);) {
            points.push_back(make_pair(l, r));
        }
        sort (all(points));
        vector <int> solution;
        int n = points.size(), pos = 0;
        for (int i = 0; i < n && pos < l;) {
            auto next = make_pair(pos, -1);
            while (i < n && points[i].x <= pos) {
                next = max (next, make_pair(points[i].y, i));
                i++;
            }
            if (next.x > pos) {
                pos = next.x;
                solution.push_back(next.y);
            } else break;
        }
        if (pos < l) {
            cout << 0 << endl;
        } else {
            if (cs) {
                cout << endl;
            }
            cout << solution.size() << endl;
            for (auto i : solution) {
                cout << points[i].x << ' ' << points[i].y << endl;
            }
        }
    }

    return 0;
}