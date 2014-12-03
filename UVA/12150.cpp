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

    int n;
    while (cin >> n && n != 0) {
        VI at(n, -1);
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            if (0 <= i + b && i + b < n)    at[i + b] = a;
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) if (at[i] == -1) {
                ok = false;
            }
        if (ok) {
            for (int i = 0; i < n; ++i) {
                cout << at[i] << (i + 1 == n ? "\n" : " ");
            }
        } else {
            cout << -1 << endl;
        }

    }

    return 0;
}
