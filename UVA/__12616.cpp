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

    VL S, SS, total;

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
        for (auto w : adj[v.x]) if (w.y != v.y) {
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
                        S[v.x] += total[w.x];
                        SS[v.x] += total[w.x] * total[w.x];
                    }
                } else if (idx[w.x] < idx[v.x]) {
                    st.push_back(w.y);
                    low[v.x] = min(low[v.x], idx[w.x]);
                }
                if (idx[w.x] > idx[v.x] && low[w.x] >= low[v.x]) {
                    total[v.x] += total[w.x];
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

        S = VL(n, 0), SS = VL(n, 0), total = VL(n, 1);
        int cnt = 0;
        for (int i = 0; i < n; i++) if (idx[i] == -1) {
                DFS(make_pair(i, -1), 0);
                for (int j = cnt; j < sz(cutVertices); ++j) {
                    cout << i << ' ' << total[i] << ' ' << cutVertices[j] << ' ' << total[cutVertices[j]] << endl;
                    S[cutVertices[j]] += total[i] - total[cutVertices[j]];
                    SS[cutVertices[j]] += (total[i] - total[cutVertices[j]]) * (total[i] - total[cutVertices[j]]);
                }
                cnt = sz(cutVertices);
            }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    BiconnectedComponents *G;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n, m;
        cin >> n >> m;
        G = new BiconnectedComponents(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            G->addEdge(a - 1, b - 1);
        }
        G->buildBCC();
        ll ans = 0;
        for (auto i : G->cutVertices) {
            cout << i << ' ' << G->S[i] << ' ' << G->SS[i] << endl;
            ans += G->S[i] * G->S[i] - G->SS[i];
        }
        cout << "Case " << cs + 1 << ": " << ans << endl;
    }

    return 0;
}