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
    
    int n;
    while (cin >> n && n != 0) {
        TarjanSCC T(n);
        map <string, int> f;
        int cnt = 0;
        VS word;

        string s;
        getline(cin, s);
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            stringstream ss(s);
            string a, b;

            ss >> a;
            if (f.find(a) == f.end()) {
                f[a] = cnt++;
                word.push_back(a);
            }
            while (ss >> b) {
                if (f.find(b) == f.end()) {
                    f[b] = cnt++;
                    word.push_back(b);
                }
                T.addEdge(f[a], f[b]);
            }
        }
        T.buildSCC();

        VI marked(n, false);
        VI st;
        VS roots;

        for (auto l: T.components) {
            if (sz(l) >= 2) {
                for (auto i: l) if (!marked[i]) {
                    st.push_back(i);
                    marked[i] = true;
                    while (!st.empty()) {
                        int u = st.back();
                        st.pop_back();
                        roots.push_back(word[u]);
                        for (auto j: T.adj[u]) if (!marked[j]) {
                            st.push_back(j);
                            marked[j] = true;
                        }
                    }
                }
            }
        }

        cout << sz(roots) << endl;
        sort(all(roots));
        cout << roots.front();
        for (int i = 1; i < sz(roots); ++i) {
            cout << ' ' << roots[i];
        }
        cout << endl;
    }

    return 0;
}