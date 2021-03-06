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
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

struct DisjointSet {
    int n;
    VI rank, parent, total;

    DisjointSet (int n): n(n), rank(n, 0), total(n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int Find (int x) {
        return parent[x] == x ? x : (parent[x] = Find(parent[x]));
    }

    bool Union (int x, int y) { // returns false if already connected
        x = Find(x), y = Find(y);
        if (x == y) {
            return false;
        } else if (rank[x] < rank[y]) {
            parent[x] = y;
            total[y] += total[x];
        } else {
            parent[y] = x;
            total[x] += total[y];
            rank[x] = max(rank[x], rank[y] + 1);
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    DisjointSet *D;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n, m;
        cin >> n >> m;
        D = new DisjointSet(n);
        for (auto& a : D->total) {
            cin >> a;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            D->Union(a, b);
        }
        string ans = "POSSIBLE";
        for (int i = 0; i < n; ++i) if (D->Find(i) == i && D->total[i] != 0) {
                ans = "IMPOSSIBLE";
            }
        cout << ans << endl;
    }

    return 0;
}