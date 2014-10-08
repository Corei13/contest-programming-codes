#include <bits/stdc++.h>

using namespace std;

#define a first
#define b second
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

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int n;
    while(cin >> n) {
        ll d;
        VL x(n), y(n);

        cin >> d;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        int ans = 1;
        VI l, r;
        VB take (n, false);
        take[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= d * d) {
                VI lft, rgt;
                for (int k = 0; k < n; ++k) if ((x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]) <= (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])
                                             && (x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]) <= (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) {
                    if (x[i] * (y[j] - y[k]) + x[j] * (y[k] - y[i]) + x[k] * (y[i] - y[j]) >= 0LL) {
                        lft.push_back(k);
                    } else {
                        rgt.push_back(k);
                    }
                }
                if (sz(lft) + sz(rgt) < ans) {
                    continue;
                } else{
                    VVI w(sz(lft), VI(sz(rgt), 0));
                    for (int k = 0; k < sz(lft); ++k) {
                        for (int l = 0; l < sz(rgt); ++l) if ((x[lft[k]] - x[rgt[l]]) * (x[lft[k]] - x[rgt[l]]) + (y[lft[k]] - y[rgt[l]]) * (y[lft[k]] - y[rgt[l]]) > d * d) {
                            w[k][l] = 1;
                        }
                    }
                    int m = BipartiteMatching(w, l, r);
                    if (ans < sz(lft) + sz(rgt) - m) {
                        ans = sz(lft) + sz(rgt) - m;
                        take = VB(n, false);
                        for (int k = 0; k < sz(lft); ++k) {
                            take[lft[k]] = true;
                        }
                        for (int l = 0; l < sz(rgt); ++l) {
                            take[rgt[l]] = true;
                        }

                        for (int k = 0; k < sz(lft); ++k) if (l[k] == -1) {
                            for (int l = 0; l < sz(rgt); ++l) if (w[k][l]) {
                                take[rgt[l]] = false;
                            }
                        }
                        for (int l = 0; l < sz(rgt); ++l) if (r[l] == -1) {
                            for (int k = 0; k < sz(lft); ++k) if (w[k][l]) {
                                take[lft[k]] = false;
                            }
                        }
                        for (int k = 0; k < sz(lft); ++k) if (l[k] != -1) {
                            if (take[lft[k]]) {
                                for (int l = 0; l < sz(rgt); ++l) if (w[k][l]) {
                                    take[rgt[l]] = false;
                                }
                            }
                        }
                        for (int l = 0; l < sz(rgt); ++l) if (r[l] != -1) {
                            if (take[rgt[l]]) {
                                for (int k = 0; k < sz(lft); ++k) if (w[k][l]) {
                                    take[lft[k]] = false;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        VI sol;
        for (int i = 0; i < n; ++i) if (take[i]) {
            sol.push_back(i);
        }
        for (int i = 0; i < sz(sol); ++i) {
            cout << sol[i] + 1 << (i + 1 == sz(sol) ? '\n' : ' ');
        }
    }
    
    return 0;
}