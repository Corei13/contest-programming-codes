/*
    Disjoint Set
*/

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
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

struct AlmostDisjointSet {
    int n;
    VI total, sum;
    VI rank, parent;

    AlmostDisjointSet (int n): n(n), rank(n, 0), total(n, 0), sum(n, 0) {
        parent = VI(2 * n);
        for (int i = 0; i < n; i++) {
            parent[i] = parent[i + n] = i;
            total[i] = 1;
            sum[i] = i + 1;
        }
    }

    int Find (int x) {
        return parent[x] == x ? x : (parent[x] = Find(parent[x]));
    }

    bool Union (int x, int y) {
        x = Find(x + n), y = Find(y + n);
        if (x == y) {
            return false;
        } else if (rank[x] < rank[y]) {
            parent[x] = y;
            total[y] += total[x];
            sum[y] += sum[x];
        } else {
            parent[y] = x;
            total[x] += total[y];
            sum[x] += sum[y];
            rank[x] = max(rank[x], rank[y] + 1);
        }
        return true;
    }

    bool Move (int x, int y) {
        int u = x;
        x = Find(x + n), y = Find(y + n);
        if (x == y) {
            return false;
        } else {
            total[x] -= 1;
            total[y] += 1;
            sum[x] -= (u + 1);
            sum[y] += (u + 1);
            parent[u + n] = y;
        }
        return true;
    }
};


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, m;
    AlmostDisjointSet *D;
    while (cin >> n >> m) {
        D = new AlmostDisjointSet(n);

        for (int q = 0; q < m; ++q) {
            int cmd;
            cin >> cmd;
            if (cmd == 1) {
                int x, y;
                cin >> x >> y;
                D->Union (x - 1, y - 1);
            } else if (cmd == 2) {
                int x, y;
                cin >> x >> y;
                D->Move (x - 1, y - 1);
            } else {
                int x;
                cin >> x;
                cout << D->total[D->Find(x + n - 1)] << ' ' << D->sum[D->Find(x + n - 1)] << endl;
            }
        }
    }

    return 0;
}