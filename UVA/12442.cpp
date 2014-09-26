#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()

typedef unsigned long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <ll, ll> PI;
typedef vector <PI> VPI;
typedef vector <VPI> VVPI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <string> VS;
typedef vector <bool> VB;
typedef vector <long double> VD;
typedef vector <VD> VVD;

PI dfs (int u, VI &next, VI &reach) {
    if (u == -1) {
        return mp(0, -1);
    } else if (reach[u] == -1) {
        reach[u] = 0;
        PI ret = dfs(next[u], next, reach);
        reach[u] = ++ret.x;
        return ret;
    } else {
        return make_pair(reach[u], reach[u] == 0 ? u : -1);
    }
}

int ammend (int u, VI &next, VI &reach) {
    int len = 0, v = u;
    do {
        len = max(len, reach[v]);
        v = next[v];
    } while (v != u);
    do {
        reach[v] = len;
        v = next[v];
    } while (v != u);
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        VI next(n, -1), reach(n, -1);
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            next[a - 1] = b - 1;
        }
        for (int i = 0; i < n; ++i) {
            PI res = dfs(i, next, reach);
            if (res.y != -1) {
                ammend(res.y, next, reach);
            }
        }
        int ans = 0, idx = 0;
        for (int i = 0; i < n; ++i) if (ans < reach[i]) {
            idx = i;
            ans = reach[i];
        }
        cout << "Case " << cs + 1 << ": " << idx + 1 << endl;
    }

    return 0;
}
