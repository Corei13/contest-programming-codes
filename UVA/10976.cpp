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
        int cnt = 0;
        for (int e = 1; e <= k; ++e) if ( (k * k) % e == 0 ) {
            cnt++;
        }
        cout << cnt << endl;
        for (int e = 1; e <= k; ++e) if ( (k * k) % e == 0 ) {
            int x = (k * k) / e + k, y = k + e;
            cout << "1/" << k << " = 1/" << x << " + 1/" << y << endl;
        }
    }

    return 0;
}
