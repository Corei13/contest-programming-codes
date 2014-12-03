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
    vector <pair <pair<T, int>, PI>> edges;
    DisjointSet *D;

    Kruskal (int n): n(n) {}

    void addEdge (int s, int t, T d, int i) {
        edges.push_back(make_pair(mp(d, i), make_pair(s, t)));
    }

    pair<T, T> MST () {
        pair<T, T> ret = make_pair(0, numeric_limits<T>::max());
        int cnt;
        VI idx;
        sort(all(edges));
        cnt = 0, D = new DisjointSet(n);
        for (auto e : edges) if (D->Union(e.y.x, e.y.y)) {
                ret.x += e.x.x;
                cnt += 1;
                idx.push_back(e.x.y);
            }
        if (cnt != n - 1) {
            return make_pair(-1, -1);
        }

        for (auto i : idx) {
            T tmp = 0;
            cnt = 0, D = new DisjointSet(n);
            for (auto e : edges) if (e.x.y != i && D->Union(e.y.x, e.y.y)) {
                    tmp += e.x.x;
                    cnt += 1;
                }
            if (cnt == n - 1) {
                ret.y = min(ret.y, tmp);
            }
        }
        if (ret.y == numeric_limits<T>::max()) {
            ret.y = -1;
        }
        return ret;
    }
};


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    Kruskal<ll> *K;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n, m;
        cin >> n >> m;
        K = new Kruskal<ll>(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            K->addEdge(a - 1, b - 1, c, i);
        }

        cout << "Case #" << cs + 1 << " : ";
        pair<ll, ll> res = K->MST();
        if (res.x == -1) {
            cout << "No way" << endl;
        } else if (res.y == -1) {
            cout << "No second way" << endl;
        } else {
            cout << res.y << endl;
        }
    }

    return 0;
}