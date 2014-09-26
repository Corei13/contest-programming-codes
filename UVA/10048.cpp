#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()

typedef unsigned long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <ll, int> PI;
typedef vector <PI> VPI;
typedef vector <VPI> VVPI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <string> VS;
typedef vector <bool> VB;
typedef vector <long double> VD;
typedef vector <VD> VVD;

const ll inf = 2000000000;

struct Dijkstra {
    int n;
    VVPI adj;
    
    Dijkstra (int n): n(n), adj(n) {}

    void addEdge (int a, int b, ll d) {
        adj[a].push_back(make_pair(d, b));
        adj[b].push_back(make_pair(d, a));
    }

    void buildTree(int s, VL &dist) {
        dist = VL(n, inf);
        priority_queue <PI, VPI, greater<PI>> q;

        dist[s] = 0;
        q.push(make_pair(dist[s], s));
        do {
            PI u = q.top();
            q.pop();
            for (auto e: adj[u.y]) if(max(u.x, e.x) < dist[e.y]) {
                dist[e.y] = max(u.x, e.x);
                q.push(make_pair(dist[e.y], e.y));
            }
        } while (!q.empty());
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int cs = 0;
    int n, m, q;

    while(cin >> n >> m >> q && n != 0) {
        VVL dist(n, VL(n, inf));
        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b;
            cin >> dist[a - 1][b - 1];
            dist[b - 1][a - 1] = dist[a - 1][b - 1];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }
        if (cs != 0) {
            cout << endl;
        }
        cout << "Case #" << ++cs << endl;
        for (int i = 0; i < q; ++i) {
            int a, b;
            cin >> a >> b;
            if (dist[a - 1][b - 1] == inf) {
                cout << "no path" << endl;
            } else {
                cout << dist[a - 1][b - 1] << endl;
            }
        }
    }

    return 0;
}
