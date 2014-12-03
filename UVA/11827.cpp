#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()

typedef unsigned long long ll;
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

    string dummy;
    getline(cin, dummy);

    for (int cs = 0; cs < t; ++cs) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        VI a;
        int n = 0, x;
        while (ss >> x) {
            a.push_back(x);
            n++;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, __gcd(a[i], a[j]));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
