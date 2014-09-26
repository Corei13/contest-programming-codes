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
        double d, v, u;
        cin >> d >> v >> u;
        cout << "Case " << cs + 1 << ": ";
        if (v == 0 || u <= v) {
            cout << "can't determine" << endl;
        } else {
            cout << fixed << setprecision(3) << d / sqrt(u * u - v * v) - d / u << endl;
        }
    }
    
    return 0;
}
