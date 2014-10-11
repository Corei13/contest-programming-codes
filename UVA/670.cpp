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
                for (auto r: adj[l]) if (dist[left[r]] == -1) {
                    dist[left[r]] = dist[l] + 1;
                    q.push(left[r]);
                }
            }
        }
        return dist[n] != -1;
    }

    bool dfs (int l) {
        if (l != n) {
            for (auto r: adj[l]) if (dist[left[r]] == dist[l] + 1 && dfs(left[r])) {
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

    void minimumVertexCover (VB &leftCover, VB &rightCover) { // {side}Cover[i] = true iff i of {side} in the the vertex cover (not in maximum independent set)
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
                for (auto r: adj[l]) if (dist[left[r]] == -1) {
                    dist[left[r]] = dist[l] + 1;
                    rightCover[r] = true;
                    q.push(left[r]);
                }
            }
        }
    }
};

double dist (PI &a, PI &b) {
    return(sqrt(double((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))));
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int t;
    HopcroftKarp* G;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n, m;
        cin >> n >> m;
        G = new HopcroftKarp(n - 1, m);
        VPI a(n), b(m);
        for (auto &u: a) {
            cin >> u.x >> u.y;
        }
        for (auto &u: b) {
            cin >> u.x >> u.y;
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j) if (dist(a[i], b[j]) + dist(b[j], a[i+1]) <= 2.0 * dist(a[i], a[i+1])) {
                G->addEdge(i, j);
            }
        }
        if (cs != 0) {
            cout << endl;
        }
        cout << n + G->match() << endl;
        for (int i = 0; i < n - 1; ++i) {
            cout << a[i].x << ' ' << a[i].y << ' ';
            if (G->right[i] != m) {
                cout << b[G->right[i]].x << ' ' << b[G->right[i]].y << ' ';
            }
        }
        cout << a.back().x << ' ' << a.back().y << endl;
    }

    return 0;
}