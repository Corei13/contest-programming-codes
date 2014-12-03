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

    T MST (int s, int t) {
        D = new DisjointSet(n);
        sort(all(edges));
        for (auto e : edges) if (D->Union(e.y.x, e.y.y)) {
                if (D->Find(s) == D->Find(t)) {
                    return e.x;
                }
            }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, m, cs = 0;
    Kruskal<int> *K;
    while (cin >> n >> m && n != 0) {
        K = new Kruskal<int>(n);
        map <string, int> f;
        for (int i = 0; i < m; ++i) {
            string s, t;
            int d;
            cin >> s >> t >> d;
            if (f.find(s) == f.end()) {
                f[s] = sz(f);
            }
            if (f.find(t) == f.end()) {
                f[t] = sz(f);
            }
            K->addEdge(f[s], f[t], -d);
        }
        string s, t;
        cin >> s >> t;
        if (f.find(s) == f.end()) {
            f[s] = sz(f);
        }
        if (f.find(t) == f.end()) {
            f[t] = sz(f);
        }
        cout << "Scenario #" << ++cs << endl << -K->MST(f[s], f[t]) << " tons" << endl << endl;
    }

    return 0;
}