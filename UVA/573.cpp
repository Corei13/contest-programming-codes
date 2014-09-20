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
    
    double height, up, down, rate;

    while (cin >> height >> up >> down >> rate && height != 0.0) {
        rate = up * rate / 100.0;
        double current = 0.0;
        for (int i = 0; ; ++i) {
            current += max(up, 0.0);
            up -= rate;
            if (current > height) {
                cout << "success on day " << i + 1 << "\n";
                break;
            }
            current -= down;
            if (current < 0.0) {
                cout << "failure on day " << i + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}