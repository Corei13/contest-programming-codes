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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 || m == 0) {
            cout << 0 << endl;
            continue;
        }
        VI x(m);
        for (auto &i: x) {
            cin >> i;
        }
        
        sort(all(x));
        if (n == 1) {
            int a = -1;
            for (auto i: x) {
                if (i != 0) {
                    a = i;
                    break;
                }
            }
            cout << (a == -1 ? 0 : a) << endl;
            continue;
        }
        VVI adj(n + 1), next(n + 1, VI(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                next[i][j] = (10 * i + x[j] + n - 1) % n + 1;
                adj[(10 * i + x[j] + n - 1) % n + 1].push_back(i);
            }
        }

        for (int j = 0; j < m; ++j) {
            next[0][j] = next[0][j] == n ? 0 : next[0][j];
        }

        VI dist(n + 1, -1);
        dist[n] = 0;
        queue <int> q;
        q.push(n);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto j: adj[u]) if (dist[j] == -1 && !(u == n && j == 0)) {
                dist[j] = dist[u] + 1;
                q.push(j);
            }
        }
        if (dist[0] == -1) {
            cout << 0 << endl;
        } else {
            int curr = 0;
            do {
                for (int j = 0; j < m; ++j) if (dist[next[curr][j]] == dist[curr] - 1) {
                    cout << x[j];
                    curr = next[curr][j];
                    break;
                }
            } while (curr != n);
            cout << endl;
        }
    }
    
    return 0;
}