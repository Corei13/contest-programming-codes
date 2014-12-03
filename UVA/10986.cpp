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

template <class T> struct Dijkstra {
    int n;
    bool directed;
    vector <vector <pair <T, int>>> adj;

    Dijkstra (int n, bool directed = false): n(n), adj(n), directed(directed) {}

    void addEdge (int a, int b, T d) {
        adj[a].push_back(make_pair(d, b));
        if (!directed) {
            adj[b].push_back(make_pair(d, a));
        }
    }

    void buildTree(int s, vector<T>& dist) {
        dist = vector <T>(n, inf);
        priority_queue <pair <T, vector<pair <T, int>>>, VPI, greater<pair <T, int>>> q;

        dist[s] = 0;
        q.push(make_pair(dist[s], s));
        do {
            PI u = q.top();
            q.pop();
            for (auto e : adj[u.y]) if (u.x + e.x < dist[e.y]) {
                    dist[e.y] = u.x + e.x;
                    q.push(make_pair(dist[e.y], e.y));
                }
        } while (!q.empty());
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    Dijkstra <ll> *D;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        D = new Dijkstra <ll>(n);
        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            D->addEdge(a, b, d);
        }
        VL dist;
        D->buildTree(s, dist);
        cout << "Case #" << cs + 1 << ": ";
        if (dist[t] == inf) {
            cout << "unreachable" << endl;
        } else {
            cout << dist[t] << endl;
        }
    }

    return 0;
}
