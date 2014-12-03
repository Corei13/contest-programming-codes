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

struct HopcroftKarp {
    int n, m;
    VVI adj;
    VI right, left;
    VI dist;

    HopcroftKarp(int n, int m): n(n), m(m), adj(n) {}

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

    int getMatching () {
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
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    HopcroftKarp *G;
    cin >> t;

    for (int cs = 0; cs < t; ++cs) {
        int n, m;
        cin >> n;
        VI a(n);
        for (auto& i : a) {
            cin >> i;
        }
        cin >> m;
        VI b(m);
        for (auto& i : b) {
            cin >> i;
        }
        G = new HopcroftKarp(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (b[j] == 0 || (a[i] != 0 && b[j] % a[i] == 0)) {
                    G->addEdge(i, j);
                }
            }
        }
        cout << "Case " << cs + 1 << ": " << G->getMatching() <<   endl;
    }

    return 0;
}
