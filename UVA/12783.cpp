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

struct BiconnectedComponents {
    int n;
    int totalComponents;
    VVPI adj;
    VPI edges;
    VI idx, low;
    VI cutVertices, bridges;
    VI st;
    VVI components;

    BiconnectedComponents (int n): n(n), adj(n) {}

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
        for (auto w: adj[v.x]) if (w.y != v.y) {
            if (idx[w.x] == -1) {
                st.push_back(w.y);
                index = DFS(w, index);
                low[v.x] = min(low[v.x], low[w.x]);
                if (low[w.x] > idx[v.x]) {
                    bridges.push_back(w.y);
                }
                children++;
                if (low[w.x] >= idx[v.x]) {
                    if (v.y != -1 || children >= 2) {
                        ap = true;
                    }
                    components.push_back(VI());
                    totalComponents++;
                    int u;
                    do {
                        u = st.back();
                        st.pop_back();
                        components.back().push_back(u);
                    } while (u != w.y);
                }
            } else if (idx[w.x] < idx[v.x]) {
                st.push_back(w.y);
                low[v.x] = min(low[v.x], idx[w.x]);
            }
        }
        if (ap) {
            cutVertices.push_back(v.x);
        }
        return index;
    }

    void buildBCC () {
        idx = VI(n, -1), low = VI(n);
        cutVertices.clear();
        bridges.clear();
        st.clear();
        components.clear();
        totalComponents++;

        for (int i = 0; i < n; i++) if (idx[i] == -1) {
            DFS(make_pair(i, -1), 0);
        }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int n, m;
    BiconnectedComponents* G;
    while (cin >> n >> m && n != 0) {
        G = new BiconnectedComponents(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            G->addEdge(min(a, b), max(a, b));
        }
        G->buildBCC();
        VPI bridges;
        for (auto i: G->bridges) {
            bridges.push_back(G->edges[i]);
        }
        sort(all(bridges));
        cout << sz(bridges);
        for (auto e: bridges) {
            cout << ' ' << e.x << ' ' << e.y;
        }
        cout << endl;
    }

    return 0;
}