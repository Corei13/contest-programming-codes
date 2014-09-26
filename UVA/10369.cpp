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
    vector <pair <ll, PI>> edges;
    DisjointSet* D;

    Kruskal (int n): n(n) {}

    void addEdge (int s, int t, ll d) {
        edges.push_back(make_pair(d, make_pair(s, t)));
    }

    ll MST (vector <pair <ll, PI>>* mst = NULL) {
        ll ret = 0;
        D = new DisjointSet(n);
        sort(all(edges));
        for (auto e: edges) if (D->Union(e.y.x, e.y.y)) {
            ret += e.x;
            if (mst) {
                mst->push_back(e);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int t;
    Kruskal* K;

    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n, sat;
        cin >> sat >> n;
        VL x(n), y(n);
        K = new Kruskal(n);

        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            for (int j = 0; j < i; ++j) {
                K->addEdge(i, j, (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
            }
        }

        vector <pair <ll, PI>> mst;
        K->MST(&mst);

        cout << fixed << setprecision(2) << sqrt(double(mst[n-sat-1].x)) << endl;
    }

    return 0;
}
