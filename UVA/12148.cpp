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

    int s[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    for (int i = 0; i < 12; ++i) {
        s[0][i + 1] += s[0][i];
        s[1][i + 1] += s[1][i];
    }
    int n;
    while (cin >> n && n != 0) {
        int yesterday = 0, today;
        int curr;
        int cnt = 0, total = 0;
        for (int i = 0; i < n; ++i) {
            int d, m, y, c;
            cin >> d >> m >> y >> c;
            today = d + s[(y % 4 == 0) && ( (y % 100 != 0) || (y % 400 == 0) )][m - 1] + (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
            if (today == yesterday + 1) {
                cnt++;
                total += c - curr;
            }
            curr = c;
            yesterday = today;
        }
        cout << cnt << ' ' << total << endl;
    }

    return 0;
}
