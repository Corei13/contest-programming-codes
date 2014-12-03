#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

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
typedef vector<bool> VB;
typedef pair<ll, ll> PI;

struct TarjanSCC {
    int n;
    int index, components;
    VVI adj;
    VI idx, component, st, low;
    VB inStack;

    TarjanSCC (int n): n(n), adj(n) {}

    void addEdge (int a, int b) {
        adj[a].push_back(b);
    }

    void DFS (int v) {
        idx[v] = index;
        low[v] = index;
        index += 1;
        st.push_back(v);
        inStack[v] = true;

        for (auto w : adj[v]) {
            if (idx[w] == -1) {
                DFS(w);
                low[v] = min(low[v], low[w]);
            } else if (inStack[w]) {
                low[v] = min(low[v], low[w]);
            }
        }

        if (low[v] == idx[v]) {
            int w;
            do {
                w = st.back();
                st.pop_back();
                inStack[w] = false;
                component[w] = components;
            } while (w != v);
            components++;
        }
    }

    void buildSCC () {
        index = 0, components = 0;
        idx = VI(n, -1), low = VI(n), component = VI(n), inStack = VB(n, false);
        st.clear();

        for (int i = 0; i < n; i++) if (idx[i] == -1) {
                DFS(i);
            }
    }
};


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int m, n;
        cin >> n >> m;
        TarjanSCC T(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            T.addEdge(a - 1, b - 1);
        }
        T.buildSCC();
        VB hasRoot(T.components, false);
        for (int i = 0; i < n; ++i) {
            for (auto j : T.adj[i]) if (T.component[i] != T.component[j]) {
                    hasRoot[T.component[j]] = true;
                }
        }
        int ans = 0;
        for (auto hr : hasRoot) if (!hr) {
                ans++;
            }
        cout << ans << endl;
    }

    return 0;
}