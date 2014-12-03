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

template <class T> struct Edge {
    int from, to, index;
    T cap, flow;

    Edge(int from, int to, T cap, T flow, int index): from(from), to(to), cap(cap), flow(flow), index(index) {}
};

template <class T> struct PushRelabel {
    int n, m;
    vector <vector <Edge <T>>> adj;
    vector <T> excess;
    VI dist, count;
    VB active;
    VVI B;
    int b, relabels, src, sink;
    queue <int> Q;

    PushRelabel (int n): n(n), adj(n) {}

    void AddEdge (int from, int to, int cap) {
        m++;
        adj[from].push_back(Edge <T>(from, to, cap, 0, adj[to].size()));
        if (from == to) {
            adj[from].back().index++;
        }
        adj[to].push_back(Edge <T>(to, from, 0, 0, adj[from].size() - 1));

    }

    void Enqueue (int v) {
        if (!active[v] && excess[v] > 0 && dist[v] < n) {
            active[v] = true;
            // cout << ">>> " << dist[v] << ' ' << v << endl;
            B[dist[v]].push_back(v);
            b = max(b, dist[v]);
        }
    }

    void Push (Edge <T>& e) {
        int amt = int(min(excess[e.from], e.cap - e.flow));
        if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) { // == -> >=
            // cout << ">    " << e.from+1 << " -> " << e.to+1 << endl;
            e.flow += amt;
            adj[e.to][e.index].flow -= amt;
            excess[e.to] += amt;
            excess[e.from] -= amt;
            Enqueue(e.to);
        }
    }

    void Gap (int k) {
        for (int v = 0; v < n; v++) if (dist[v] >= k) {
                count[dist[v]]--;
                dist[v] = max(dist[v], n); // n -> n+1
                count[dist[v]]++;
                Enqueue(v);
            }
    }

    void GlobalRelabel () {
        dist = VI(n, n);
        B = VVI(n);
        dist[sink] = 0;
        Q.push(sink);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (auto e : adj[v]) {
                int w = e.to;
                if (dist[w] == n && adj[w][e.index].cap > adj[w][e.index].flow) {
                    dist[w] = dist[v] + 1;
                    Q.push(w);
                }
            }
        }
        b = 0;
        count = VI(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            active[i] = false;
            Enqueue(i);
            count[dist[i]]++;
        }
    }

    void Relabel (int v) {
        count[dist[v]]--;
        dist[v] = n;
        for (auto e : adj[v]) if (e.cap - e.flow > 0) {
                dist[v] = min(dist[v], dist[e.to] + 1);
            }
        count[dist[v]]++;
        Enqueue(v);
        relabels++;
    }

    void Discharge(int v) {
        for (auto& e : adj[v]) {
            if (excess[v] > 0) {
                Push(e);
            } else {
                break;
            }
        }

        if (excess[v] > 0) {
            if (count[dist[v]] == 1) {
                Gap(dist[v]);
            } else {
                Relabel(v);
            }
        }
    }

    T GetMaxFlow (int s, int t) {
        src = s, sink = t;
        dist = VI(n, 0), excess = vector<T>(n, 0), count = VI(n + 1, 0), active = VB(n, false), B = VVI(n), b = 0, relabels = 0;

        for (auto& e : adj[s]) {
            excess[s] += e.cap;
        }

        count[0] = n;
        Enqueue(s);
        active[t] = true;

        while (b >= 0) {
            if (!B[b].empty()) {
                int v = B[b].back();
                B[b].pop_back();
                active[v] = false;
                Discharge(v);
            } else {
                b--;
            }
        }

        // phase II

        return excess[t];
    }

    T GetMinCut (int s, int t, VI& cut);
};



int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    PushRelabel<ll> *P;
    int n, cs = 0;

    while (cin >> n && n != 0) {
        P = new PushRelabel<ll> (n);
        int s, t, m;
        cin >> s >> t >> m;
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            P->AddEdge(a - 1, b - 1, c);
            P->AddEdge(b - 1, a - 1, c);
        }
        cout << "Network " << ++cs << endl << "The bandwidth is " << P->GetMaxFlow(s - 1, t - 1) << "." << endl << endl;
    }

    return 0;
}
