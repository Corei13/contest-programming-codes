#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <ll, ll> PI;
typedef vector <PI> VPI;
typedef vector <VPI> VVPI;

typedef vector <ll> VL;
typedef vector <VL> VVL;

typedef vector <long double> VD;
typedef vector <VD> VVD;


int n, inf = 1000000000;
VI from, to, dist;
VVPI adj, revadj;

void dijkstraForward ( int src ) {
    from = VI(n, inf);    
    from[src] = 0;
    set <PI> pq;
    
    pq.insert(mp(0, src));
    do {
        set<PI>::iterator u = pq.begin();
        for (VPI::iterator it = adj[u->y].begin(); it != adj[u->y].end(); it++) {
            if ( from[u->y] + it->y < from[it->x] ) {
                from[it->x] = from[u->y] + it->y;
                pq.insert(mp(from[it->x], it->x));
            }
        }
        pq.erase(u);
    } while ( !pq.empty() );
}

void dijkstraBackward (int src) {
    to = VI(n, inf);
    to[src] = 0;
    set <PI> pq;
    
    pq.insert(mp(0, src));
    do {
        set<PI>::iterator u = pq.begin();
        for (VPI::iterator it = revadj[u->y].begin(); it != revadj[u->y].end(); it++) {
            if ( to[u->y] + it->y < to[it->x] ) {
                to[it->x] = to[u->y] + it->y;
                pq.insert(mp(to[it->x], it->x));
            }
        }
        pq.erase(u);
    } while ( !pq.empty() );
}

int dijkstraLast (int src, int dst, int shortestDist) {
    dist = VI(n, inf);
    dist[src] = 0;
    set <PI> pq;
    
    pq.insert(mp(0, src));
    do {
        set<PI>::iterator u = pq.begin();
        for (VPI::iterator it = adj[u->y].begin(); it != adj[u->y].end(); it++) {
            if ( dist[u->y] + it->y < dist[it->x] && from[u->y] + it->y + to[it->x] > shortestDist ) {
                dist[it->x] = dist[u->y] + it->y;
                pq.insert(mp(dist[it->x], it->x));
            }
        }
        pq.erase(u);
    } while ( !pq.empty() );
    return dist[dst] == inf ? -1 : dist[dst];
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int m;
    while (cin >> n >> m && n != 0) {
        adj = VVPI(n);
        revadj = VVPI(n);
        int src, dst;
        cin >> src >> dst;
        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].pb(mp(b, d));
            revadj[b].pb(mp(a, d));
        }
        dijkstraForward(src);
        dijkstraBackward(dst);
        cout << dijkstraLast(src, dst, from[dst]) << endl;
    }

    return 0;
}
