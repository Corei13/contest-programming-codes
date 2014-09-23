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

    int n, cs = 0;
    while (cin >> n && n != 0) {
        VI a(n);
        for (auto &i: a) {
            cin >> i;
        }
        int q;
        cin >> q;
        cout << "Case " << ++cs << ":" << endl;
        for (int i = 0; i < q; ++i) {
            int s, ans = a[0] + a[1];
            cin >> s;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < j; ++k) {
                    if (abs(a[j] + a[k] - s) < abs(ans - s)) {
                        ans = a[j] + a[k];
                    }
                }
            }
            cout << "Closest sum to " << s << " is " << ans << "." << endl;
        }
    }
    
    return 0;
}
