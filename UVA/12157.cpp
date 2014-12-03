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

    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n, mile = 0, juice = 0, best;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int d;
            cin >> d;
            mile += (1 + d / 30) * 10;
            juice += (1 + d / 60) * 15;
        }
        best = min(mile, juice);
        cout << "Case " << cs + 1 << ": " << (best == mile ? "Mile " : "") << (best == juice ? "Juice " : "") << best << endl;
    }

    return 0;
}