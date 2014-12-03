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
typedef pair <int, int> PI;
typedef vector <PI> VPI;
typedef vector <VPI> VVPI;

typedef vector <ll> VL;
typedef vector <VL> VVL;

typedef vector <string> VS;
typedef vector <long double> VD;
typedef vector <VD> VVD;


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        set <int> s;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            s.insert(a);
        }
        int t;
        cin >> t;
        int i = 0;
        for (auto a : s) if (2 * a <= t && s.find(t - a) != s.end()) {
                i = max(i, a);
            }
        cout << "Peter should buy books whose prices are " << i << " and " << t - i << "." << endl << endl;
    }

    return 0;
}
