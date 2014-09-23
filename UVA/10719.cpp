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

    ll k;
    while (cin >> k) {
        string s;
        getline(cin, s);
        getline(cin, s);
        stringstream ss(s);
        VL v;
        ll a;
        while (ss >> a) {
            v.push_back(a);
        }
        reverse(all(v));
        int n = sz(v);
        cout << "q(x):";
        while ( sz(v) != 1 ) {
            ll u = v.back();
            v.pop_back();
            v.back() += k * u;
            cout << ' ' << u;
        }
        cout << endl;
        cout << "r = " << v.back() << endl << endl;
    }

    return 0;
}
