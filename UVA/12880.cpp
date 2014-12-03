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
    vector <vector <int>> adj;
    vector <int> right, left;
    vector <int> dist;

    HopcroftKarp (int n, int m): n(n), m(m), adj(n + 1) {}

    void AddEdge (int l, int r) {
        adj[l].push_back(r);
    }

    bool BFS () {
        queue <int> q;
        dist = vector <int>(n + 1, -1);
        for (int l = 1; l <= n; ++l) if (right[l] == 0) {
                dist[l] = 0;
                q.push(l);
            }

        while (!q.empty()) {
            int l = q.front();
            q.pop();
            if (dist[0] == -1 || dist[l] < dist[0]) {
                for (auto& r : adj[l]) if (dist[left[r]] == -1) {
                        dist[left[r]] = dist[l] + 1;
                        q.push(left[r]);
                    }
            }
        }
        return dist[0] != -1;
    }

    inline bool DFS (int l) {
        if (l != 0) {
            for (auto& r : adj[l]) if (dist[left[r]] == dist[l] + 1 && DFS(left[r])) {
                    left[r] = l;
                    right[l] = r;
                    return true;
                }
            dist[l] = -1;
            return false;
        }
        return true;
    }

    int Match () {
        right = vector <int>(n + 1, 0);
        left = vector <int>(m + 1, 0);
        int ret = 0;
        while (BFS()) {
            for (int l = 1; l <= n; ++l) if (right[l] == 0 && DFS(l)) {
                    ret++;
                }
        }
        return ret;
    }

    /*
        Finds minimum vertex cover

        Running time:
            O(|V|+|E|)

        Output:
            - leftCover, leftCover[l] is true iff node l of the left side is in the minimum vertex cover
            (not in the maximum independent set)
            - leftCover, rightCover[r] is true iff node r of the right side is in the minimum vertex cover
            (not in the maximum independent set)
    */

    void MinimumVertexCover (vector <bool>& leftCover, vector <bool>& rightCover) {
        leftCover = vector <bool>(n + 1, true), rightCover = vector <bool>(m + 1, false);
        queue <int> q;
        dist = vector <int>(n + 1, -1);
        for (int l = 1; l <= n; ++l) if (right[l] == 0) {
                dist[l] = 0;
                q.push(l);
            }

        while (!q.empty()) {
            int l = q.front();
            q.pop();
            leftCover[l] = false;
            if (dist[0] == -1 || dist[l] < dist[0]) {
                for (auto& r : adj[l]) if (dist[left[r]] == -1) {
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

    int n, m;
    HopcroftKarp *G;
    while (cin >> n >> m) {
        G = new HopcroftKarp (n, n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            G->AddEdge(a + 1, b + 1);
        }
        cout << (G->Match() == n ? "YES" : "NO") << endl;
    }

    return 0;
}