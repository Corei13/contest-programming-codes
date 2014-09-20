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
    
    int t, n;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        cin >> n;
        int m = 100, M = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            m = min(m, a);
            M = max(M, a);
        }
        cout << 2 * (M - m) << endl;
    }

    return 0;
}