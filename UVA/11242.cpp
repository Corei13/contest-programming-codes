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

    int n, m;
    while (cin >> n && n != 0) {
        cin >> m;
        VD a(n), b(m), ratio;
        for (auto &f: a) {
            cin >> f;
        }
        for (auto &r: b) {
            cin >> r;
            for (auto f: a) {
                ratio.push_back(r / f);
            }
        }
        sort(all(ratio));
        long double ans = 0;
        for (int i = 0; i < sz(ratio)-1; ++i) {
            ans = max(ans, ratio[i+1] / ratio[i]);
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
    
    return 0;
}
