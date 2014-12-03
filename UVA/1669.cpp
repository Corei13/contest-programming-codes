/*
    DFS, Tree
    For each edge count the number of people which will cross that road
*/

#include <bits/stdc++.h>

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
typedef vector<VVL> VVVL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<int, ll> PI;
typedef vector<PI> VPI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

int n;
VVPI adj;

PI dfs (int i, ll w, int p) { // returns <child, answer for tree>
    PI ret = make_pair(0, 0);
    for (auto u : adj[i]) if (u.x != p) {
            PI res = dfs(u.x, u.y, i);
            ret.x += res.x;
            ret.y += res.y;
        }
    ret.x += 1;
    ret.y += w * (ll) min(ret.x, n - ret.x);
    return ret;
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        cin >> n;
        adj = VVPI(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            ll d;
            cin >> a >> b >> d;
            adj[a - 1].push_back(make_pair(b - 1, d));
            adj[b - 1].push_back(make_pair(a - 1, d));
        }
        cout << "Case #" << cs + 1 << ": " << 2LL * dfs(0, 0, -1).y << endl;
    }

    return 0;
}