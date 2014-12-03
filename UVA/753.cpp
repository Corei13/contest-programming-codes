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
typedef pair<ll, ll> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

struct HopcroftKarp {
    int n, m;
    VVI adj;
    VI right, left;
    VI dist;

    HopcroftKarp (int n, int m): n(n), m(m), adj(n) {}

    void addEdge (int l, int r) {
        adj[l].push_back(r);
    }

    bool bfs () {
        queue <int> q;
        dist = VI(n + 1, -1);
        for (int l = 0; l < n; ++l) if (right[l] == m) {
                dist[l] = 0;
                q.push(l);
            }

        while (!q.empty()) {
            int l = q.front();
            q.pop();
            if (dist[n] == -1 || dist[l] < dist[n]) {
                for (auto r : adj[l]) if (dist[left[r]] == -1) {
                        dist[left[r]] = dist[l] + 1;
                        q.push(left[r]);
                    }
            }
        }
        return dist[n] != -1;
    }

    bool dfs (int l) {
        if (l != n) {
            for (auto r : adj[l]) if (dist[left[r]] == dist[l] + 1 && dfs(left[r])) {
                    left[r] = l;
                    right[l] = r;
                    return true;
                }
            dist[l] = -1;
            return false;
        }
        return true;
    }

    int match () {
        right = VI(n, m);
        left = VI(m, n);
        int ret = 0;
        while (bfs()) {
            for (int l = 0; l < n; ++l) if (right[l] == m && dfs(l)) {
                    ret++;
                }
        }
        return ret;
    }

    void minimumVertexCover (VB& leftCover, VB& rightCover) { // {side}Cover[i] = true iff i of {side} in the the vertex cover (not in maximum independent set)
        leftCover = VB(n, true), rightCover = VB(m, false);
        queue <int> q;
        dist = VI(n + 1, -1);
        for (int l = 0; l < n; ++l) if (right[l] == m) {
                dist[l] = 0;
                q.push(l);
            }

        while (!q.empty()) {
            int l = q.front();
            q.pop();
            leftCover[l] = false;
            if (dist[n] == -1 || dist[l] < dist[n]) {
                for (auto r : adj[l]) if (dist[left[r]] == -1) {
                        dist[left[r]] = dist[l] + 1;
                        rightCover[r] = true;
                        q.push(left[r]);
                    }
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    HopcroftKarp *G;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n, m;
        cin >> m;
        map<string, int> f;
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            f[s] = i;
        }
        cin >> n;
        VI plug(n);
        for (int i = 0, cnt = m; i < n; ++i) {
            string dummy, s;
            cin >> dummy >> s;
            if (!f.count(s)) {
                f[s] = cnt++;
            }
            plug[i] = f[s];
        }
        G = new HopcroftKarp(n, m);
        int adapters;
        cin >> adapters;
        VVB closure(m + n + 2 * adapters, VB(m + n + 2 * adapters, false));
        for (int i = 0, cnt = sz(f); i < adapters; ++i) {
            string a, b;
            cin >> a >> b;
            if (!f.count(a)) {
                f[a] = cnt++;
            }
            if (!f.count(b)) {
                f[b] = cnt++;
            }
            closure[f[a]][f[b]] = true;
        }
        for (int k = 0; k < sz(f); ++k) {
            for (int i = 0; i < sz(f); ++i) {
                for (int j = 0; j < sz(f); ++j) {
                    closure[i][j] = closure[i][j] or (closure[i][k] and closure[k][j]);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            closure[i][i] = true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) if (closure[plug[i]][j]) {
                    G->addEdge(i, j);
                }
        }
        if (cs != 0) {
            cout << endl;
        }
        cout << n - G->match() << endl;
    }

    return 0;
}