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
typedef pair<int, ll> PI;
typedef vector<PI> VPI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

struct DisjointSet {
    int n;
    VI rank, parent, v, e;

    DisjointSet (int n): n(n), rank(n, 0), v(n, 1), e(n, 0) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int Find (int x) {
        return parent[x] == x ? x : (parent[x] = Find(parent[x]));
    }

    bool Union (int x, int y) { // returns false if already connected
        x = Find(x), y = Find(y);
        if (x == y) {
            e[x]++;
            return false;
        } else if (rank[x] < rank[y]) {
            parent[x] = y;
            v[y] += v[x];
            e[y] += e[x];
            e[y]++;
        } else {
            parent[y] = x;
            v[x] += v[y];
            e[x] += e[y];
            e[x]++;
            rank[x] = max(rank[x], rank[y] + 1);
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, e;
    DisjointSet *D;
    while (cin >> n >> e) {
        D = new DisjointSet(256);
        for (int i = 0; i < e; ++i) {
            char a, b;
            cin >> a >> b;
            D->Union(a, b);
        }
        int face = 1;
        for (int i = 0; i < D->n; ++i) if (D->Find(i) == i) {
                face += D->e[i] - D->v[i] + 1;
            }
        cout << face << endl;
    }
}