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
    
    int n, m;
    while (cin >> n >> m && n != 0) {
        VI r(n);
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            r[b - 1] += c;
            r[a - 1] -= c;
        }
        char ans = 'S';
        for (int i = 0; i < n; ++i) if (r[i] < 0) {
            ans = 'N';
            break;    
        }
        cout << ans << endl;
    }

    return 0;
}