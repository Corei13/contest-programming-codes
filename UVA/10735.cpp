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

struct EulerTour {
    int n, e;
    VVPI adj;
    VI ideg, odeg;
    list<int> tour;

    EulerTour(int n): n(n), adj(n), ideg(n), odeg(n), e(0) {}

    void addEdge(int a, int b, bool directed = false) {
        adj[a].push_back(make_pair(b, e));
        odeg[a]++, ideg[b]++;
        if (!directed) {
            adj[b].push_back(make_pair(a, e));
            odeg[b]++, ideg[a]++;
        }
        e++;
    }

    void startTour(int start = 0) {
        tour.clear();
        tour.push_back(start);
        vector<VPI::iterator> iter;
        for (auto &v: adj) {
            iter.push_back(v.begin());
        }
        VB visited(e, false);
        for (auto it = tour.begin(); it != tour.end(); it++) {
            int u = *it, v = u;
            auto pos = next(it);
            do {
                while (iter[v] != adj[v].end() && visited[iter[v]->y]) {
                        iter[v]++;
                    }
                    if (iter[v] == adj[v].end()) {
                        break;
                    } else {
                        visited[iter[v]->y] = true;
                        iter[v]++;
                        v = prev(iter[v])->x;
                        tour.insert(pos, v);
                    }
            } while (v != u);
        }
    }
};

struct HopcroftKarp { // 1-based indexing
    int n, m;
    VVI adj;
    VI right, left;
    VI dist;

    HopcroftKarp (int n, int m): n(n), m(m), adj(n + 1) {}

    void addEdge (int l, int r) {
        adj[l + 1].push_back(r + 1);
    }
    
    bool bfs () {
        queue <int> q;
        dist = VI(n + 1, -1);
        for (int l = 1; l <= n; ++l) if (right[l] == 0) {
            dist[l] = 0;
            q.push(l);
        }
        while (!q.empty()) {
            int l = q.front();
            q.pop();
            if (dist[0] == -1 || dist[l] < dist[0]) {
                for (auto r: adj[l]) if (dist[left[r]] == -1) {
                    dist[left[r]] = dist[l] + 1;
                    q.push(left[r]);
                }
            }
        }
        return dist[0] != -1;
    }

    bool dfs (int l) {
        if (l != 0) {
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
        right = VI(n + 1, 0);
        left = VI(m + 1, 0);
        int ret = 0;
        while (bfs()) {
            for (int l = 1; l <= n; ++l) if (right[l] == 0 && dfs(l)) {
                ret++;
            }
        }
        return ret;
    }

    void minimumVertexCover (VB &leftCover, VB &rightCover) { // {side}Cover[i] = true iff i of {side} in the the vertex cover (not in maximum independent set)
        leftCover = VB(n + 1, true), rightCover = VB(m + 1, false);
        queue <int> q;
        dist = VI(n + 1, -1);
        for (int l = 1; l <= n; ++l) if (right[l] == 0) {
            dist[l] = 0;
            q.push(l);
        }

        while (!q.empty()) {
            int l = q.front();
            q.pop();
            leftCover[l] = false;
            if (dist[0] == -1 || dist[l] < dist[0]) {
                for (auto r: adj[l]) if (dist[left[r]] == -1) {
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
    EulerTour* E;
    cin >> t;

    for (int cs = 0; cs < t; ++cs) {
        int n, e;
        cin >> n >> e;
        VI d(n + 1, 0);
        vector<pair<char, PI>> edges(e);
        VI idx(e);

        for (int i = 0; i < e; ++i) {
            cin >> edges[i].y.x >> edges[i].y.y >> edges[i].x;
            d[edges[i].y.x]++, d[edges[i].y.y]++;
        }
        bool possible = true;
        for (int i = 1; i <= n; ++i) if (d[i] % 2 == 1) {
            possible = false;
        }
        if (possible) {
            G = new HopcroftKarp(e, e);
            for (int i = 1, cnt = 0; i <= n; cnt += d[i] / 2, i += 1) {
                for (int k = 0; k < d[i] / 2; ++k) {
                    idx[cnt+k] = i;
                }
                for (int j = 0; j < e; ++j) {
                    if (edges[j].y.y == i) {
                        for (int k = 0; k < d[i] / 2; ++k) {
                            G->addEdge(j, cnt + k);
                        }
                    }
                    if (edges[j].x == 'U' && edges[j].y.x == i) {
                        for (int k = 0; k < d[i] / 2; ++k) {
                            G->addEdge(j, cnt + k);
                        }
                    }
                }
            }
            if (G->match() != e) {
                possible = false;
            }
        }
        if (cs != 0) {
            cout << endl;
        }
        if (possible) {
            E = new EulerTour(n);
            for (int i = 0; i < e; ++i) {
                E->addEdge(((edges[i].y.x ^ edges[i].y.y) ^ idx[G->right[i+1]-1]) - 1, idx[G->right[i+1]-1] - 1, true);
            }
            E->startTour();
            for (auto it = E->tour.begin(); it != E->tour.end(); it++) {
                cout << *it + 1;
                if (next(it) == E->tour.end())  {
                    cout << endl;
                } else {
                    cout << ' ';
                }
            }
        } else {
            cout << "No euler circuit exist" << endl;
        }
    }


    return 0;
}
