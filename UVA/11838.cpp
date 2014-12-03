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
typedef vector<string> VS;
typedef pair<ll, ll> PI;

struct TarjanSCC {
    int n;
    int index, totalComponents;
    VVI adj;
    VS   components;
    VI idx, componentOf, st, low;
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
            components.push_back(string(""));
            do {
                w = st.back();
                st.pop_back();
                inStack[w] = false;
                componentOf[w] = totalComponents;
                components[totalComponents] += char(w + 'A');
            } while (w != v);
            sort(all(components[totalComponents]));
            totalComponents++;
        }
    }

    void buildSCC () {
        index = 0, totalComponents = 0;
        idx = VI(n, -1), low = VI(n), componentOf = VI(n), inStack = VB(n, false);
        st.clear();

        for (int i = 0; i < n; i++) if (idx[i] == -1) {
                DFS(i);
            }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m && n >= 1) {
        TarjanSCC T(n);
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            T.addEdge(a - 1, b - 1);
            if (c == 2) {
                T.addEdge(b - 1, a - 1);
            }
        }
        T.buildSCC();
        cout << int(sz(T.components) == 1) << endl;
    }

    return 0;
}