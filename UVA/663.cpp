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
    VVB w;
    VI right, left;
    VI dist;

    HopcroftKarp(int n, int m): n(n), m(m), w(n, VB(m)) {}

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
                for (int r = 0; r < m; r++) if (w[l][r] && dist[left[r]] == -1) {
                        dist[left[r]] = dist[l] + 1;
                        q.push(left[r]);
                    }
            }
        }
        return dist[n] != -1;
    }

    bool dfs (int l) {
        if (l != n) {
            for (int r = 0; r < m; r++) if (w[l][r] && dist[left[r]] == dist[l] + 1 && dfs(left[r])) {
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

    int n, cs = 0;
    HopcroftKarp *G;
    while (cin >> n && n != 0) {
        vector<pair<PI, PI>> slide(n);
        VPI label(n);
        G = new HopcroftKarp(n, n);
        VI unique;

        for (int i = 0; i < n; ++i) {
            cin >> slide[i].x.x >> slide[i].x.y >> slide[i].y.x >> slide[i].y.y;
        }
        for (int i = 0; i < n; ++i) {
            cin >> label[i].x >> label[i].y;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (slide[i].x.x <= label[j].x && label[j].x <= slide[i].x.y && slide[i].y.x <= label[j].y && label[j].y <= slide[i].y.y) {
                    G->w[i][j] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (G->w[i][j]) {
                    G->w[i][j] = false;
                    if (G->getMatching() != n) {
                        unique.push_back(i);
                    }
                    G->w[i][j] = true;
                }
        }
        G->getMatching();
        cout << "Heap " << ++cs << endl;
        if (unique.empty()) {
            cout << "none";
        }
        for (int i = 0; i < sz(unique); ++i) {
            if (i != 0) {
                cout << " ";
            }
            cout << "(" << char(unique[i] + 'A') << "," << G->right[unique[i]] + 1 << ")";
        }
        cout << endl << endl;
    }

    return 0;
}