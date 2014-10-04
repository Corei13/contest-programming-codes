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
    VI rank, parent, parity;

    DisjointSet (int n): n(n), rank(n, 0), parity(n, 0) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int Find (int x) {
        if (parent[x] != x) {
            Find(parent[x]);
            parity[x] ^= parity[parent[x]];
            parent[x] = parent[parent[x]];
        }
        return parent[x];
    }

    bool Union (int x, int y, int diff) {
        int ux = x, uy = y;
        x = Find(x), y = Find(y);
        if (x == y) {
            return (parity[ux] ^ parity[uy]) == diff;
        } else if (rank[x] < rank[y]) {
            parent[x] = y;
            parity[x] = parity[ux] ^ diff ^ parity[uy];
        } else {
            parent[y] = x;
            parity[y] = parity[uy] ^ diff ^ parity[ux];
            rank[x] = max(rank[x], rank[y] + 1);
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    DisjointSet* D = new DisjointSet(n);
    enum {
        done,
        setFriends,
        setEnemies,
        areFriends,
        areEnemies
    } cmd;
    int c, x, y;
    while (cin >> c >> x >> y){
        switch (c) {
            case setFriends:
                if(!D->Union(x, y, 0)) {
                    cout << -1 << endl;
                }
                break;
            case setEnemies:
                if(!D->Union(x, y, 1)) {
                    cout << -1 << endl;
                }
                break;
            case areFriends:
                if(D->Find(x) == D->Find(y) && (D->parity[x] ^ D->parity[y]) == 0) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
                break;
            case areEnemies:
                if(D->Find(x) == D->Find(y) && (D->parity[x] ^ D->parity[y]) == 1) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
                break;
            default:
                return 0;
        }
    }
}