#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<ll, ll> PI;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n, m = 200, M = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            m = min(m, a - b);
            M = max(M, a - b);
        }
        cout << (M == m ? "yes" : "no") << endl;
        if (cs + 1 < t) cout << endl;
    }

    return 0;
}