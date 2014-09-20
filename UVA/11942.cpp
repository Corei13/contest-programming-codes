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
    cout << "Lumberjacks:" << endl;
    for (int cs = 0; cs < t; ++cs) {
        VI x(10), ord;
        for (int i = 0; i < 10; ++i) {
            cin >> x[i];
        }
        ord = x;
        sort(all(ord));
        string ans = "Ordered";
        for (int i = 0; i < 10; ++i) if (ord[i] != x[i]) {
            ans = "Unordered";
        }
        if (ans == "Unordered") {
            ans = "Ordered";
            reverse(all(ord));
            for (int i = 0; i < 10; ++i) if (ord[i] != x[i]) {
                ans = "Unordered";
            }
        }
        cout << ans << endl;
    }

    return 0;
}