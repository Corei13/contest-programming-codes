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

string name[16];
double pr[32][16], w[16][16];

double get (int at, int l, int r, int i) {
    if (pr[at][i] != -1.0) {
        return pr[at][i];
    } else if (l == r) {
        return pr[at][i] = 1.0;
    } else{
        pr[at][i] = 0.0;
        int mid = (l + r) / 2;
        if (i <= mid) {
            for (int j = mid + 1; j <= r; ++j) {
                pr[at][i] += get(at * 2 + 1, mid + 1, r, j) * w[i][j];
            }
            pr[at][i] *= get(at * 2, l, mid, i);
        } else {
            for (int j = l; j <= mid; ++j) {
                pr[at][i] += get(at * 2, l, mid, j) * w[i][j];
            }
            pr[at][i] *= get(at * 2 + 1, mid + 1, r, i);
        }
        return pr[at][i];
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            pr[i][j] = -1.0;
        }
    }
    for (int i = 0; i < 16; ++i) {
        cin >> name[i];
    }
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            cin >> w[i][j];
            w[i][j] /= 100.0;
        }
    }
    for (int i = 0; i < 16; ++i) {
        cout << left << setw(10) << name[i] << " p=" << fixed << setprecision(2) << get(1, 0, 15, i) * 100 << "%" << endl;
    }
    return 0;
}