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
    
    int n, cs = 0;
    while (cin >> n) {
        VS names(n);
        map<string, int> give, get;
        for (int i = 0; i < n; ++i) {
            cin >> names[i];
            get[names[i]] = 0;
        }
        for (int i = 0; i < n; ++i) {
            string s;
            int k;
            cin >> s;
            cin >> give[s] >> k;
            for (int j = 0; j < k; ++j) {
                string t;
                cin >> t;
                get[t] += give[s] / k;
            }
            if (k)  give[s] = (give[s] / k) * k;
            else    give[s] = 0;
        }
        if (cs++ != 0)    cout << endl;
        for (auto s: names) {
            cout << s << ' ' << -give[s] + get[s] << endl;
        }
    }

    return 0;
}