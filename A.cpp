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

typedef long long LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
    dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
    Gap(dist[v]); 
      else
    Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    PushRelabel *P;
    EulerTour* E;
    cin >> t;

    for (int cs = 0; cs < t; ++cs) {
        int n, e;
        cin >> n >> e;
        P = new PushRelabel(2 * n + 2 + e);
        VI d(n + 1, 0);
        for (int i = 0; i < e; ++i) {
            int a, b;
            char dir;
            cin >> a >> b >> dir;
            P->AddEdge(0, 2 * n + 2 + i, 1);
            P->AddEdge(2 * n + 2 + i, a, 1);
            P->AddEdge(a, b + n, 1);
            if (dir == 'U') {
                P->AddEdge(2 * n + 2 + i, b, 1);
                P->AddEdge(b, a + n, 1);
            }
            d[a]++, d[b]++;
        }
        bool possible = true;
        for (int i = 1; i <= n; ++i) if (d[i] % 2 == 1) {
            possible = false;
        }
        if (possible) {
            for (int i = 1; i <= n; ++i) {
                P->AddEdge(i + n, 2 * n + 1, d[i] / 2);
            }
            if (P->GetMaxFlow(0, 2 * n + 1) != e) {
                possible = false;
            }
        }
        if (cs != 0) {
            cout << endl;
        }
        if (possible) {
            E = new EulerTour(n);
            for (int i = 1; i <= n; ++i) {
                for (auto e: P->G[i]) if (2 * n >= e.to && e.to >= n + 1){
                    // E->addEdge(i - 1, e.to - n - 1, true);
                    // cout << i << ' ' << e.to - n << endl;
                    cout << e.from << ' ' << e.to - n << ' ' << e.flow << ' ' << e.cap << endl;
                }
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
