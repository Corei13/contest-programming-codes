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
    VVI adj, components;
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

        for (auto w: adj[v]) {
            if (idx[w] == -1) {
                DFS(w);
                low[v] = min(low[v], low[w]);
            } else if (inStack[w]) {
                low[v] = min(low[v], low[w]);                
            }
        }

        if (low[v] == idx[v]) {
            int w;
            components.push_back(VI());
            do {
                w = st.back();
                st.pop_back();
                inStack[w] = false;
                componentOf[w] = totalComponents;
                components[totalComponents].push_back(w);
            } while (w != v);
            totalComponents++;
        }
    }

    void buildSCC () {
        index = 0, totalComponents = 0;
        idx = VI(n,-1), low = VI(n), componentOf = VI(n), inStack = VB(n, false);
        st.clear();
        
        for (int i = 0; i < n; i++) if (idx[i] == -1) {
            DFS(i);
        }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int m, n, cs = 0;
    while (cin >> n >> m && n != 0) {
        TarjanSCC T(n);
        map <string, int> f;
        int cnt = 0;
        VS names;

        for (int i = 0; i < m; ++i) {
            string a, b;
            cin >> a >> b;
            if (f.find(a) == f.end()) {
                f[a] = cnt++;
                names.push_back(a);
            }
            if (f.find(b) == f.end()) {
                f[b] = cnt++;
                names.push_back(b);
            }
            T.addEdge(f[a], f[b]);
        }
        T.buildSCC();
        if (cs >= 1) {
            cout << endl;
        }
        cout << "Calling circles for data set " << ++cs << ":" << endl;
        for (auto v: T.components) {
            cout << names[v.front()];
            for (int i = 1; i < sz(v); ++i) {
                cout << ", " << names[v[i]];
            }
            cout << endl;
        }
    }

    return 0;
}