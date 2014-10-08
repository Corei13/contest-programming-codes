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

ll MinCostMatching(const VVL &cost, VL &Lmate, VL &Rmate) {
  int n = int(cost.size());

  // construct dual feasible solution
  VL u(n);
  VL v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }
  
  // construct primal solution satisfying complementary slackness
  Lmate = VL(n, -1);
  Rmate = VL(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (cost[i][j] == u[i] + v[j]) {
    Lmate[i] = j;
    Rmate[j] = i;
    mated++;
    break;
      }
    }
  }
  
  VL dist(n);
  VL dad(n);
  VL seen(n);
  
  // repeat until primal solution is feasible
  while (mated < n) {
    
    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;
    
    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++) 
      dist[k] = cost[s][k] - u[s] - v[k];
    
    int j = 0;
    while (true) {
      
      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
    if (seen[k]) continue;
    if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;
      
      // termination condition
      if (Rmate[j] == -1) break;
      
      // relax neighbors
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
    if (seen[k]) continue;
    const ll new_dist = dist[j] + cost[i][k] - u[i] - v[k];
    if (dist[k] > new_dist) {
      dist[k] = new_dist;
      dad[k] = j;
    }
      }
    }
    
    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];
    
    // augment along path
    while (dad[j] >= 0) {
      const ll d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;
    
    mated++;
  }
  
  ll value = 0;
  for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];
  
  return value;
}



int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    ll inf = 100000000;
    int n;
    while (cin >> n) {
        VVL w(n, VL(n, inf * inf));
        VI a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (a[j] == 1) {
                w[i][j] = inf;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1, cost = 1; j < n; ++j) {
                if (a[j] == a[i] + 1) {
                    w[i][j] = cost;
                    break;
                } else if (a[j] > a[i]) {
                    cost++;
                }
            }
            for (int j = i - 1, cost = 1; j >= 0; --j) {
                if (a[j] == a[i] + 1) {
                    w[i][j] = cost;
                    break;
                } else if (a[j] > a[i]) {
                    cost++;
                }
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << '\t' << '\t' << '\t' << w[i][j];
        //     }
        //     cout << endl;
        // }
        VL l, r;
        ll cost = MinCostMatching(w, l, r);
        for (int i = 0; i < n; ++i) if (a[i] == 1) {
            cost -= inf;
        }
        if (cost >= inf * inf) {
            cout << "impossible" << endl;
        } else {
            cout << cost << endl;
        }
    }
    
    return 0;
}