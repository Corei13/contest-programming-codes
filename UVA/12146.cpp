#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <ll, ll> PI;
typedef vector <PI> VPI;
typedef vector <VPI> VVPI;

typedef vector <ll> VL;
typedef vector <VL> VVL;

typedef vector <long double> VD;
typedef vector <VD> VVD;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int a, b;
    while (cin >> a >> b && a * b != 0) {
        VVI row(a+1, VI(b+1, 0));
        VI grid(a+1, 0);
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                int x;
                cin >> x;
                row[i][j+1] = max(x + (j >= 1 ? row[i][j-1] : 0), row[i][j]);
            }
        }
        for (int i = 0; i < a; ++i) {
            grid[i+1] = max(row[i][b] + (i >= 1 ? grid[i-1] : 0), grid[i]);
        }
        cout << grid[a] << endl;
    }

    return 0;
}
