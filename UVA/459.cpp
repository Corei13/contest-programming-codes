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
    VI rank, parent;

    DisjointSet (int n): n(n), rank(n, 0) {
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
        } else {
            parent[y] = x;
            rank[x] = max(rank[x], rank[y] + 1);
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    DisjointSet* D;
    int t;
    cin >> t;
    
    for (int cs = 0; cs < t; ++cs) {
        char n;
        cin >> n;
        D = new DisjointSet(n + 1 - 'A');
        string s;
        getline(cin, s);

        while (getline(cin, s) && s != "") {
            stringstream ss(s);
            char a, b;
            ss >> a >> b;
            D->Union(a - 'A', b - 'A');
        }

        for (int i = 0; i < D->n; ++i) {
            D->Find(i);
        }

        if (cs != 0)    cout << endl;
        cout << sz(set<int>(all(D->parent))) << endl;
    }

    return 0;
}