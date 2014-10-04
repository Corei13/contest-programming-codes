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

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int cs = 0; cs < t; ++cs) {
        int n, tree;
        cin >> n >> tree;
        VPI hash(n, mp(0, 0));
        string s;
        getline(cin, s);
        while(getline(cin, s) && s != "") {
            stringstream ss(s);
            int a, b;
            ss >> a >> b;
            --a, --b;
            if (b < 50) {
                hash[a].x |= (1LL << b);
            } else {
                hash[a].y |= (1LL << (b - 50));
            }
        }
        if (cs != 0) {
            cout << endl;
        }
        cout << sz(set<PI>(all(hash))) << endl;
    }

    return 0;
}