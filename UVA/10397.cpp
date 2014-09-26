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

struct DisjointSet {
    int n;
    VI rank, parent;

    DisjointSet (int n): n(n), rank(n) {
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


struct Kruskal {
    int n;
    vector <pair <double, PI>> edges;
    DisjointSet* D;

    Kruskal (int n): n(n), D(new DisjointSet(n)) {}

    void addEdge (int s, int t, double d) {
        edges.push_back(make_pair(d, make_pair(s, t)));
    }

    double MST () {
        double ret = 0.0;
        sort(all(edges));
        for (auto e: edges) if (D->Union(e.y.x, e.y.y)) {
            ret += e.x;
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int n;
    Kruskal* K;

    while (cin >> n) {
        VD x(n), y(n);
        K = new Kruskal(n);

        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            for (int j = 0; j < i; ++j) {
                K->addEdge(i, j, sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j])));
            }
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            K->D->Union(a - 1, b - 1);
        }

        cout << fixed << setprecision(2) << (K->MST()) << endl;
    }

    return 0;
}
