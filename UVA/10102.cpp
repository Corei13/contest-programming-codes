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
        VPI src, dst;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                if (s[j] == '1') {
                    src.push_back(mp(i, j));
                } else if (s[j] == '3') {
                    dst.push_back(mp(i, j));
                }
            }
        }
        int ans = 0;
        for (auto s: src) {
            int curr = n * n;
            for (auto t: dst) {
                curr = min(curr, abs(s.x - t.x) + abs(s.y - t.y));
            }
            ans = max(curr, ans);
        }
        cout << ans << endl;
    }
    
    return 0;
}
