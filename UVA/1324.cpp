#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

using namespace std;

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

template <class T> struct Edge {
    int from, to, index;
    T cap, flow;

    Edge(int from, int to, T cap, T flow, int index): from(from), to(to), cap(cap), flow(flow), index(index) {}
};

template <class T> struct PushRelabel {
    int n;
    vector <vector <Edge <T>>> adj;
    vector <T> excess;
    vector <int> dist, count;
    vector <bool> active;
    vector <vector <int>> B;
    int b;
    queue <int> Q;

    PushRelabel (int n): n(n), adj(n) {}

    void AddEdge (int from, int to, T cap) {
        if (from != to) {
            adj[from].push_back(Edge <T>(from, to, cap, 0, adj[to].size()));
            adj[to].push_back(Edge <T>(to, from, 0, 0, adj[from].size() - 1));
        }
    }

    void Enqueue (int v) {
        if (!active[v] && excess[v] > 0 && dist[v] < n) {
            active[v] = true;
            B[dist[v]].push_back(v);
            b = max(b, dist[v]);
        }
    }

    void Push (Edge <T> &e) {
        T amt = min(excess[e.from], e.cap - e.flow);
        if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) {
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
            dist[v] = max(dist[v], n);
            count[dist[v]]++;
            Enqueue(v);
        }
    }

    void Relabel (int v) {
        count[dist[v]]--;
        dist[v] = n;
        for (auto &e: adj[v]) if (e.cap - e.flow > 0) {
            dist[v] = min(dist[v], dist[e.to] + 1);
        }
        count[dist[v]]++;
        Enqueue(v);
    }

    void Discharge(int v) {
        for (auto &e: adj[v]) {
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

    void Init () {
        excess = VI(n, 0);
        active = vector <bool>(n, false);
        for (int i = 0; i < n; ++i) {
            for (auto &e: adj[i]) {
                e.flow = 0;
            }
        }
    }

    T GetMaxFlow (int s, int t) {
        dist = vector <int>(n, 0), count = vector <int>(n + 1, 0);
        B = vector <vector <int>>(n);
        b = 0;
        
        for (auto &e: adj[s]) {
            excess[s] += e.cap;
        }

        count[0] = n;
        for (int i = 0; i < n; ++i) {
            Enqueue(i);
        }
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
        return excess[t];
    }

    void PreflowToFlow (int s, int t) {
        enum color {WHITE, GREY, BLACK};
        vector <color> rank (n, WHITE);
        vector <int> prev (n, -1);
        vector <typename vector <Edge <T>>::iterator> current;
        vector <int> st;
        for (int i = 0; i < n; ++i) {
            current.push_back (adj[i].begin());
        }

        for (int i = 0; i < n; ++i) {
            if (rank[i] == WHITE && excess[i] > 0 && i != s && i != t) {
                int r = i;
                rank[r] = GREY;
                do {
                    while (current[i] != adj[i].end()) {
                        auto e = current[i];
                        if (e->cap == 0 && e->cap - e->flow > 0 && e->to != s && e->to != t) {
                            int j = e->to;
                            if (rank[j] == WHITE) {
                                rank[j] = GREY;
                                prev[j] = i;
                                i = j;
                                break;
                            } else if (rank[j] == GREY) {
                                T amt = e->cap - e->flow;
                                do {
                                    amt = min (amt, current[j]->cap - current[j]->flow);
                                    if (j != i) {
                                        j = current[j]->to;
                                    }
                                } while (j != i);

                                do {
                                    e = current[j];
                                    e->flow += amt;
                                    adj[e->to][e->index].flow -= amt;
                                    j = e->to;
                                } while (j != i);

                                int restart = i;
                                for(j = current[i]->to; j != i; j = e->to) {
                                    e = current[j];
                                    if(rank[j] == WHITE || e->cap - e->flow == 0) {
                                        rank[current[j]->to] = WHITE;
                                        if(rank[j] != WHITE) {
                                            restart = j;
                                        }
                                    }
                                }

                                if (restart != i) {
                                    i = restart;
                                    current[i]++;
                                    break;
                                }
                            }
                        }
                        current[i]++;
                    }
                    if(current[i] == adj[i].end()) {
                        rank[i] = BLACK;
                        if(i != s) {
                            st.push_back(i);
                        }

                        if(i != r) {
                            i = prev[i];
                            current[i]++;
                        } else {
                            break;
                        }
                    }
                } while (true);
            }
        }

        while (!st.empty()) {
            int i = st.back();
            st.pop_back();

            auto e = adj[i].begin();

            while(excess[i] > 0) {
                if(e->cap == 0 && e->cap - e->flow > 0 ) {
                    T amt = min( excess[i], e->cap - e->flow );
                    e->flow += amt;
                    adj[e->to][e->index].flow -= amt;
                    excess[i] -= amt;
                    excess[e->to] += amt;
                }
                e++;
            }
        }
    }

    /*
        Finds minimal cut with source and sink

        Running time:
            O(|V|+|E|)

        Output:
            - cut, cut[u] =
                 0, if u belongs to the minimal cut containing source,
                 1, if u belongs to the minimal cut containing sink,
                -1, otherwise
    */

    T GetMinCut (int s, int t, vector <int> &cut) {
        T ret = GetMaxFlow(s, t);
        PreflowToFlow(s, t);
        cut = vector <int> (n, -1);
        queue<int> Q;

        Q.push(s);
        cut[s] = 0;

        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (auto &e: adj[u]) if (cut[e.to] == -1 && e.cap - e.flow > 0) {
                Q.push(e.to);
                cut[e.to] = 0;
            }
        }

        Q.push(t);
        cut[t] = 1;

        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (auto &e: adj[u]) if (cut[e.to] == -1 && adj[e.to][e.index].cap - adj[e.to][e.index].flow > 0) {
                Q.push(e.to);
                cut[e.to] = 1;
            }
        }

        return ret;
    }

    void DFS (int u) {

    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    PushRelabel <int> *G;
    int n, m, k, s, t;
    while (cin >> n >> m >> k >> s >> t) {
        --s, --t;
        
        int l = n + k;
        G = new PushRelabel <int> (n * (l + 1) + 2);
        
        VPI edges;

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            edges.push_back(make_pair(a, b));
        }

        G->Init();
        for (int i = 1; i <= l; ++i) {
            for (auto &e: edges) {
                G->AddEdge((i - 1) * n + e.x, i * n + e.y, 1);
                G->AddEdge((i - 1) * n + e.y, i * n + e.x, 1);
            }
            G->AddEdge (n * (l + 1), (i - 1) * n + s, k);
            G->AddEdge (i * n + t, n * (l + 1) + 1, k);

            int flow = G->GetMaxFlow(n * (l + 1), n * (l + 1) + 1);
            if (flow >= k) {
                cout << i << endl;
                G->PreflowToFlow(n * (l + 1), n * (l + 1) + 1);

                VVPI path(i + 1);
                for (int u = 0; u < k; ++u) {
                    int current = n * (l + 1);
                    do {
                        for (auto &e: G->adj[current]) if (e.flow > 0) {
                            e.flow--;
                            current = e.to;
                            if ((e.to - e.from) % n != 0 && e.to % n != s) {
                                path[e.to / n].push_back(make_pair(u, e.to % n));
                            }
                            break;
                        }
                    } while (current % n != t);
                }
                for (int j = 1; j <= i; ++j) {
                    cout << int(path[j].size());
                    for (auto p: path[j]) {
                        cout << " " << p.x + 1 << " " << p.y + 1;
                    }
                    cout << endl;
                }

                break;
            }
        }
        delete G;
    }
    return 0;
}