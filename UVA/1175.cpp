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

void stableMatching (int n, VVI& maleRank, VVI& femaleRank, VI& wife) {
    // a male m prefers w to w' if maleRank[m][w] < maleRank[m][w']
    // returns male-optimal matching

    VI freeMen;
    VVPI fq(n);
    VI husband(n, -1);
    for (int m = 0; m < n; ++m) {
        for (int w = 0; w < n; ++w) {
            fq[m].push_back(make_pair(maleRank[m][w], w));
        }
        sort(all(fq[m]), greater<PI>());
        freeMen.push_back(m);
    }
    while (!freeMen.empty()) {
        int m = freeMen.back(), w = fq[m].back().y;
        fq[m].pop_back();
        if (husband[w] == -1) {
            husband[w] = m;
            freeMen.pop_back();
        } else if (femaleRank[w][m] < femaleRank[w][husband[w]]) {
            freeMen.pop_back();
            freeMen.push_back(husband[w]);
            husband[w] = m;
        }
    }
    wife = VI(n);
    for (int w = 0; w < n; ++w) {
        wife[husband[w]] = w;
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n;
        cin >> n;
        VVI frank(n, VI(n)), mrank(n, VI(n));
        for (int w = 0; w < n; ++w) {
            for (int i = 0; i < n; ++i) {
                int m;
                cin >> m;
                frank[w][m - 1] = i;
            }
        }
        for (int m = 0; m < n; ++m) {
            for (int i = 0; i < n; ++i) {
                int w;
                cin >> w;
                mrank[m][w - 1] = i;
            }
        }
        VI match;
        stableMatching(n, frank, mrank, match);
        if (cs != 0) {
            cout << endl;
        }
        for (int i = 0; i < n; ++i) {
            cout << match[i] + 1 << endl;
        }
    }
    return 0;
}