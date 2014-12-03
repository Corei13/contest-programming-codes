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
        string s, t;
        cin >> s >> t;
        int a = sz(s), b = sz(t);
        VVI match(a + 1, VI(b + 1, 0));
        VVI lcs[2] = {VVI(a + 1, VI(b + 1, 0)), VVI(a + 1, VI(b + 1, -10000))};
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                if (s[i] == t[j]) {
                    match[i + 1][j + 1] = 1 + match[i][j];
                }
                lcs[0][i + 1][j + 1] = max(max(lcs[0][i][j + 1], lcs[1][i][j + 1]), max(lcs[0][i + 1][j], lcs[1][i + 1][j]));
                if (match[i + 1][j + 1] >= n) {
                    lcs[1][i + 1][j + 1] = n + max(lcs[0][i - n + 1][j - n + 1], lcs[1][i - n + 1][j - n + 1]);
                }
                if (match[i + 1][j + 1] > n) {
                    lcs[1][i + 1][j + 1] = max(lcs[1][i + 1][j + 1], 1 + lcs[1][i][j]);
                }
            }
        }
        cout << max(lcs[0][a][b], lcs[1][a][b]) << endl;
    }

    return 0;
}
