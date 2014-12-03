#include <bits/stdc++.h>

using namespace std;

#define a first
#define b second
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

    void getMinimumVertexCover(VB& leftCover, VB& rightCover) { // {side}Cover[i] = true iff i of {side} in the the vertex cover (not in maximum independent set)
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

    int n;
    HopcroftKarp *G;
    while (cin >> n) {
        ll d;
        VL x(n), y(n);

        cin >> d;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        int ans = 1;
        VB take (n, false);
        take[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= d * d) {
                    VI lft, rgt;
                    for (int k = 0; k < n; ++k) if ((x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]) <= (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])
                                                        && (x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]) <= (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) {
                            if (x[i] * (y[j] - y[k]) + x[j] * (y[k] - y[i]) + x[k] * (y[i] - y[j]) >= 0LL) {
                                lft.push_back(k);
                            } else {
                                rgt.push_back(k);
                            }
                        }
                    if (sz(lft) + sz(rgt) <= ans) {
                        continue;
                    } else if (lft.empty() || rgt.empty()) {
                        ans = sz(lft) + sz(rgt);
                        take = VB(n, false);
                        for (auto i : lft) {
                            take[i] = true;
                        }
                        for (auto i : rgt) {
                            take[i] = true;
                        }
                    } else {
                        G = new HopcroftKarp(sz(lft), sz(rgt));
                        for (int k = 0; k < sz(lft); ++k) {
                            for (int l = 0; l < sz(rgt); ++l) if ((x[lft[k]] - x[rgt[l]]) * (x[lft[k]] - x[rgt[l]]) + (y[lft[k]] - y[rgt[l]]) * (y[lft[k]] - y[rgt[l]]) > d * d) {
                                    G->addEdge(k, l);
                                }
                        }
                        int m = G->getMatching();
                        if (ans < sz(lft) + sz(rgt) - m) {
                            ans = sz(lft) + sz(rgt) - m;
                            take = VB(n);
                            VB l, r;
                            G->getMinimumVertexCover(l, r);
                            for (int i = 0; i < sz(lft); ++i) {
                                take[lft[i]] = !l[i];
                            }
                            for (int i = 0; i < sz(rgt); ++i) {
                                take[rgt[i]] = !r[i];
                            }
                        }
                    }
                }
        }
        cout << ans << endl;
        VI sol;
        for (int i = 0; i < n; ++i) if (take[i]) {
                sol.push_back(i);
            }
        for (int i = 0; i < sz(sol); ++i) {
            cout << sol[i] + 1 << (i + 1 == sz(sol) ? '\n' : ' ');
        }
    }

    return 0;
}