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


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        if (cs != 0) {
            cout << endl;
        }
        int n;
        cin >> n;
        VS s(n);
        VI l(n), r(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i] >> l[i] >> r[i];
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int p, idx = -1;
            cin >> p;
            for (int j = 0; j < n && idx != -2; ++j) if (l[j] <= p && p <= r[j]) {
                    idx = idx == -1 ? j : -2;
                }
            cout << (idx < 0 ? "UNDETERMINED" : s[idx]) << endl;
        }
    }

    return 0;
}
