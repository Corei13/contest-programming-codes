/*
    RMQ
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

ll find(int k, int l, int r, VVI &a, VI &ret) {
    if (l == r) {
        ret = a[l];
    } else {
        int mid = (l + r) / 2;
        VI lft, rgt;
        find(k, l, mid, a, lft);
        find(k, mid+1, r, a, rgt);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; (i + 1) * (j + 1) <= k; ++j)
            {
                ret.push_back(lft[i] + rgt[j]);
            }
        }
        sort(all(ret));
        ret.resize(k);
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int k;
    while(cin >> k) {
        VVI a(k, VI(k));
        for (auto &row: a) {
            for (auto &c: row) {
                cin >> c;
            }
            sort(all(row));
        }
        
        VI res;
        find(k, 0, k - 1, a, res);
        for (int i = 0; i < k; ++i) {
            cout << res[i] << (i + 1 == k ? '\n' : ' ');
        }
    }
    
    return 0;
}