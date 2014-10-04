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
    
    int t;
    DisjointSet* D;
    cin >> t;
    for (int cs = 0; cs < t; ++cs)
    {
        int n, a = 0, b = 0;
        cin >> n;
        D = new DisjointSet(n);
        char cmd;
        int x, y;
        string s;
        getline(cin, s);
        while (getline(cin, s) && s != "") {
            stringstream ss(s);
            ss >> cmd >> x >> y;
            if (cmd == 'c') {
                D->Union(x - 1, y - 1);
            } else {
                if (D->Find(x - 1) == D->Find(y - 1)) {
                    a++;
                } else {
                    b++;
                }
            }
        }
        if (cs != 0) {
            cout << endl;
        }
        cout << a << "," << b << endl;
    }


    return 0;
}