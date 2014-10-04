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
typedef pair<ll, ll> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

struct DisjointSet {
    int n;
    VI rank, parent, total;

    DisjointSet (int n): n(n), rank(n, 0), total(n, 1) {
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
            return false;
        } else if (rank[x] < rank[y]) {
            parent[x] = y;
            total[y] += total[x];
        } else {
            parent[y] = x;
            total[x] += total[y];
            rank[x] = max(rank[x], rank[y] + 1);
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int n, m;
    DisjointSet* D;
    while (cin >> n >> m && n != 0) {
        map<string, int> f;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            f[s] = i;
        }
        D = new DisjointSet(n);
        for (int i = 0; i < m; ++i) {
            string a, b;
            cin >> a >> b;
            D->Union(f[a], f[b]);
        }
        int largest = 0;
        for (int i = 0; i < n; ++i) {
            largest = max(largest, D->total[i]);
        }
        cout << largest << endl;
    }

    return 0;
}