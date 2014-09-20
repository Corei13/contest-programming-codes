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
    
    int offset, y, m, d;
    int t[2][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    }, s[2][13];
    s[0][0] = 0;
    s[1][0] = 0;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 12; ++i) {
            s[j][i+1] = s[j][i] + t[j][i];
        }
    }
    
    #define isLeap(y) ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))

    while (cin >> offset >> d >> m >> y && !(offset == 0 && d == 0 && m == 0 && y == 0)) {
        --d, --m, --y;

        d = 365 * y + s[isLeap(y + 1)][m] + d + y / 4 - y / 100 + y / 400 + offset, y = 0, m = 0;
        //cout << ">>> " << d << endl;
        int tmp = d / (400 * 365 + 100 - 4 + 1);
        y += 400 * tmp;
        d -= (400 * 365 + 100 - 4 + 1) * tmp;
        //cout << ">>> " << d << endl;
        tmp = min(3, d / (100 * 365 + 25 - 1));
        y += 100 * tmp;
        d -= (100 * 365 + 25 - 1) * tmp;
        //cout << ">>> " << d << endl;
        tmp = min(24, d / (4 * 365 + 1));
        y += 4 * tmp;
        d -= (4 * 365 + 1) * tmp;
        //cout << ">>> " << d << endl;
        tmp = min(3, d / 365);
        y += tmp;
        d -= 365 * tmp;
        //cout << ">>> " << d << endl;
        while (d >= t[isLeap(y+1)][m]) {
            d -= t[isLeap(y+1)][m];
            m++;
        }
        cout << d + 1 << ' ' << m + 1 << ' ' << y + 1<< endl;

    }

    return 0;
}