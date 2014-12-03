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

        VI h(n), w(n), inc(n), dec(n);
        for (auto& a : h) {
            cin >> a;
        }
        for (auto& a : w) {
            cin >> a;
        }
        for (int i = 0; i < n; ++i) {
            inc[i] = dec[i] = w[i];
            for (int j = 0; j < i; ++j) {
                if (h[j] < h[i]) {
                    inc[i] = max (inc[i], w[i] + inc[j]);
                } else if (h[j] > h[i]) {
                    dec[i] = max (dec[i], w[i] + dec[j]);
                }
            }
        }
        int il = 0, dl = 0;
        for (auto l : inc) {
            il = max(il, l);
        }
        for (auto l : dec) {
            dl = max(dl, l);
        }
        cout << "Case " << cs + 1 << ". ";
        if (il >= dl) {
            cout << "Increasing (" << il << "). Decreasing (" << dl << ")." << endl;
        } else {
            cout << "Decreasing (" << dl << "). Increasing (" << il << ")." << endl;
        }
    }

    return 0;
}