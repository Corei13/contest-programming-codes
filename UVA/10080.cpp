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
typedef pair<double, double> PI;
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

    int n, m;
    HopcroftKarp *G;
    while (cin >> n >> m) {
        G = new HopcroftKarp(n, m);
        double s, v;
        cin >> s >> v;
        VPI gopher(n), hole(m);
        for (auto& p : gopher) {
            cin >> p.x >> p.y;
        }
        for (auto& p : hole) {
            cin >> p.x >> p.y;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) if ((gopher[i].x - hole[j].x) * (gopher[i].x - hole[j].x) + (gopher[i].y - hole[j].y) * (gopher[i].y - hole[j].y) <= s * s * v * v) {
                    G->addEdge(i, j);
                }
        }
        cout << n - G->getMatching() << endl;
    }

    return 0;
}