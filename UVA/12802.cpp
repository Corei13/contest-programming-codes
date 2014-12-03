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

bool check (string n) {
    int v = atoi(n.c_str());
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return true;
        }
    }
    for (int i = 0; i < sz(n); ++i) if (n[i] != n[sz(n) - i - 1]) {
            return true;
        }
    return false;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    string n;
    do {
        cin >> n;
        cout << 2 * atoi(n.c_str()) << endl;
    } while (check(n));

    return 0;
}