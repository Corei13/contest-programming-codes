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
    DisjointSet* D;

    Kruskal (int n): n(n) {}

    void addEdge (int s, int t, T d) {
        edges.push_back(make_pair(d, make_pair(s, t)));
    }

    T MST (int s, int t) {
        D = new DisjointSet(n);
        sort(all(edges));
        for (auto e: edges) if (D->Union(e.y.x, e.y.y)) {
            if (D->Find(s) == D->Find(t)) {
                return e.x;
            }
        }
        return -1; // error
    }
};

void print (int s, int t, VVI &best) {
    if (best[s][t] == t) {
        cout << ' ' << t + 1;
    } else {
        print (s, best[s][t], best);
        print (best[s][t], t, best);
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, m;
    Kruskal<int> *K;
    while (cin >> n >> m) {
        K = new Kruskal<int>(n);

        int s, t;
        cin >> s >> t;
        --s, --t;

        vector<pair<pair<int, int>, pair<int, int>>> edges;
        for (int i = 0; i < m; ++i) {
            int a, b;
            double d, temp;
            cin >> a >> b >> temp >> d;
            --a, --b;
            K->addEdge(a, b, int(10.0 * temp + 0.5));
            edges.push_back(make_pair(make_pair(int(10.0 * d + 0.5), int(10.0 * temp + 0.5)), make_pair(a, b)));
        }
        
        int maxTemp = K->MST(s, t);

        VVI w(n, VI(n, 1000000000));
        VVI best(n, VI(n, -1));

        for (auto e: edges) if (e.x.y <= maxTemp) {
            if (e.x.x < w[e.y.x][e.y.y]) {
                w[e.y.x][e.y.y] = e.x.x;
                best[e.y.x][e.y.y] = e.y.y;
            }
            if (e.x.x < w[e.y.y][e.y.x]) {
                w[e.y.y][e.y.x] = e.x.x;
                best[e.y.y][e.y.x] = e.y.x;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) if (w[i][k] + w[k][j] < w[i][j]) {
                    w[i][j] = w[i][k] + w[k][j];
                    best[i][j] = k;
                }
            }
        }
        cout << s + 1;
        print(s, t, best);
        cout << endl << fixed << setprecision(1) << w[s][t] / 10.0 << ' ' << maxTemp  / 10.0 << endl;
    }
    
    
    return 0;
}