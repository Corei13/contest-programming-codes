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

    int n, k;
    double down, owe;
    while (cin >> n >> down >> owe >> k && n >= 0) {
        double val = owe + down, rate = owe / double(n);
        int m;
        double r;
        cin >> m >> r;
        int curr = 0, ans = -1;
        for (int i = 1; i < k; ++i) {
            cin >> m;
            for (; curr < m; ++curr) {
                val *= 1.0 - r;
                if (owe < val && ans == -1) {
                    ans = curr;
                }
                owe -= rate;
            }
            cin >> r;
        }
        for (; ans == -1; ++curr) {
            val *= 1.0 - r;
            if (owe < val && ans == -1) {
                ans = curr;
            }
            owe -= rate;
        }
        cout << ans << " month" << (ans != 1 ? "s" : "") << endl;
    }

    return 0;
}