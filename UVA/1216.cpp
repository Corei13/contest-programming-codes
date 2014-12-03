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

    T MST (int k) {
        if (k >= n) {
            return 0;
        }
        int cnt = 0;
        D = new DisjointSet(n);
        sort(all(edges));
        for (auto e : edges) if (D->Union(e.y.x, e.y.y)) {
                cnt++;
                if (cnt == n - k) {
                    return e.x;
                }
            }
        return -1; // error!
    }
};

ll mceil (ll a) {
    ll r = (ll)(sqrt(a) + 1e-6);
    if (r * r == a) {
        return r;
    } else {
        return r + 1;
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    Kruskal<ll> *K;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n = 0, k;
        cin >> k;
        VL x, y;
        int a, b;
        while (cin >> a && a != -1) {
            cin >> b;
            x.push_back(a);
            y.push_back(b);
            n++;
        }
        K = new Kruskal<ll>(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                K->addEdge(i, j, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            }
        }
        cout << mceil(K->MST(k)) << endl;
    }

    return 0;
}