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
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<ll, ll> PI;

struct TarjanSCC {
    int n;
    int index, totalComponents;
    VVI adj;
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
            do {
                w = st.back();
                st.pop_back();
                inStack[w] = false;
                componentOf[w] = totalComponents;
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

int n;
VVL w;
VL dist;

bool check (ll d, ll e) {
    TarjanSCC T(2*n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (w[i][j] > d) {
                T.addEdge(i, j+n);
            }
            if (w[i][j] > e) {
                T.addEdge(i+n, j);
            }
        }
    }
    T.buildSCC();
    for (int i = 0; i < n; ++i) if (T.componentOf[i] == T.componentOf[i+n]) {
        return false;
    }
    return true;
}

bool checkTotal (ll D) {
    for (int d = 0; d < sz(dist) && dist[d] <= D; ++d) if (check (dist[d], D-dist[d])) {
        return true;
    }
    return false;
}

int find (ll lo, ll hi) {
    if (lo == hi) {
        return lo;
    }
    ll mid = (lo + hi) / 2LL;
    if (checkTotal(mid)) {
        return find (lo, mid);
    } else {
        return find (mid+1LL, hi);
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    while (cin >> n) {
        w = VVL(n, VL(n, 0));
        dist.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cin >> w[i][j];
                w[j][i] = w[i][j];
                dist.push_back(w[i][j]);
            }
        }
        sort(all(dist));
        cout << find(0, dist.back()) << endl;
    }

    return 0;
}