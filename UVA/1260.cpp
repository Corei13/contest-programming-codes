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
        int n;
        cin >> n;
        VI a(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < i; ++j) {
                ans += (a[j] <= a[i]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
