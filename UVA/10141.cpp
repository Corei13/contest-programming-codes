#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<ll, ll> PI;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int n, p, cs = 0;
    while (cin >> n >> p && n != 0) {
        string dummy, name, best;
        double best_price = 1e30;
        int best_req = -1;
        getline(cin, dummy);
        for (int i = 0; i < n; ++i) {
            getline(cin, dummy);
        }
        for (int i = 0; i < p; ++i) {
            getline(cin, name);
            double price;
            int req;
            cin >> price >> req;
            if (req > best_req || (req == best_req && price < best_price)) {
                best = name;
                best_req = req;
                best_price = price;
            }
            getline(cin, dummy);
            for (int j = 0; j < req; ++j) {
                getline(cin, dummy);
            }
        }
        if (cs >= 1)    cout << endl;
        cout << "RFP #" << ++cs << endl << best << endl;
    }

    return 0;
}