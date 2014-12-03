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

    T MST (int start, T best, int& last) {
        if (last + 1 >= sz(edges) || edges[last + 1].x - edges[start].x >= best) {
            last = max(last, start + n - 1);
            return -2;
        }
        D = new DisjointSet(n);
        if  (start == 0) {
            sort(all(edges));
        }
        int cnt = 0;
        for (int i = start; i < sz(edges); ++i) {
            if (D->Union(edges[i].y.x, edges[i].y.y)) {
                last = i;
                cnt++;
                if (cnt == n - 1) {
                    return edges[i].x - edges[start].x;
                }
            }
            if (edges[i].x - edges[start].x >= best) {
                return -2;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n;
    Kruskal<ll> *K;
    while (cin >> n && n != 0) {
        int m;
        cin >> m;
        K = new Kruskal<ll>(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            ll d;
            cin >> a >> b >> d;
            K->addEdge(a, b, d);
        }
        ll ans = numeric_limits<ll>::max();
        int last = 0;
        for (int i = 0; i < m; ++i) {
            ll res = K->MST(i, ans, last);
            if (res == -1) {
                break;
            } else if (res != -2) {
                ans = min(ans, res);
            }
        }
        cout << ans << endl;
    }

    return 0;
}