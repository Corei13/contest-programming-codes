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
typedef vector <bool> VB;
typedef vector <long double> VD;
typedef vector <VD> VVD;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int l, n;
        cin >> l >> n;
        VB possible(l + 1, false);
        possible[0] = true;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            for (int j = l; j >= a; j--) {
                possible[j] = possible[j] or possible[j - a];
            }
        }
        cout << (possible[l] ? "YES" : "NO") << endl;

    }

    return 0;
}
