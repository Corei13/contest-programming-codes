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

struct DisjointSet {
    int n;
    VI rank, parent;

    DisjointSet (int n): n(n), rank(n, 0) {
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
        } else {
            parent[y] = x;
            rank[x] = max(rank[x], rank[y] + 1);
        }
        return true;
    }
};

template <class T> struct Kruskal {
    int n;
    vector <pair <T, PI>> edges;
    DisjointSet *D;

    Kruskal (int n): n(n) {}

    void addEdge (int s, int t, T d) {
        edges.push_back(make_pair(d, make_pair(s, t)));
    }

    T MST (int start, T best) {
        D = new DisjointSet(n);
        if  (start == 0) {
            sort(all(edges));
        }
        int cnt = 0;
        for (int i = start; i < sz(edges) && edges[i].x - edges[start].x < best; ++i) {
            if (D->Union(edges[i].y.x, edges[i].y.y)) {
                cnt++;
                if (cnt == n - 1) {
                    return edges[i].x - edges[start].x;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, m;
    Kruskal<int> *K;
    while (cin >> n >> m && n != 0) {
        K = new Kruskal<int>(n);
        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            K->addEdge(a - 1, b - 1, d);
        }
        int ans = 1000000000;
        for (int i = 0; i < m; ++i) {
            int res = K->MST(i, ans);
            if (res != -1) {
                ans = min(ans, res);
            }
        }
        cout << (ans == 1000000000 ? -1 : ans) << endl;
    }

    return 0;
}