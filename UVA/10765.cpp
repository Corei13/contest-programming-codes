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
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

struct CutVerticesAndBridges {
    int n;
    VVPI adj;
    VPI edges;
    VI idx, low;
    VI cutVertices, bridges;
    VPI pigeon;

    CutVerticesAndBridges (int n): n(n), adj(n) {}

    void addEdge (int a, int b) {
        int i = sz(edges);
        adj[a].push_back(make_pair(b, i));
        adj[b].push_back(make_pair(a, i));
        edges.push_back(make_pair(a, b));
    }

    int DFS (PI v, int index) {
        idx[v.x] = index;
        low[v.x] = index;
        index += 1;

        int children = 0;
        bool ap = false;
        for (auto w : adj[v.x]) if (w.y != v.y) {
                if (idx[w.x] == -1) {
                    index = DFS(w, index);
                    low[v.x] = min(low[v.x], low[w.x]);
                    if (low[w.x] > idx[v.x]) {
                        bridges.push_back(w.x);
                    }
                    children++;
                    if ((v.y == -1 && children >= 2) || (v.y != -1 && low[w.x] >= idx[v.x])) {
                        ap = true;
                        pigeon[v.x].x++;
                    }
                } else {
                    low[v.x] = min(low[v.x], idx[w.x]);
                }
            }
        if (ap) {
            cutVertices.push_back(v.x);
        }
        return index;
    }

    void build () {
        idx = VI(n, -1), low = VI(n);
        cutVertices.clear();
        bridges.clear();
        pigeon = VPI(n);
        for (int i = 0; i < n; ++i) {
            pigeon[i] = make_pair(1, -i);
        }

        for (int i = 0; i < n; i++) if (idx[i] == -1) {
                DFS(make_pair(i, -1), 0);
            }
    }
};


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, k;
    CutVerticesAndBridges *C;
    while (cin >> n >> k && n != 0) {
        C = new CutVerticesAndBridges(n);
        int a, b;
        while (cin >> a >> b && a != -1) {
            C->addEdge(a, b);
        }
        C->build();
        sort(all(C->pigeon), greater<PI>());
        for (int i = 0; i < k; ++i) {
            cout << -C->pigeon[i].y << ' ' << C->pigeon[i].x << endl;
        }
        cout << endl;
    }

    return 0;
}