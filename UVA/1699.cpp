#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef vector<int> VI;


int n;
double x[128], y[128], cx, cy, lx, rx, T, A, a, b;

ll fl (double r) {
    return (ll)(r);
}

ll ce (double r) {
    double a = (ll)(r);
    if (r - a < 1e-15) {
        return (ll)(r);
    } else {
        return (ll)(r) + 1LL;
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    while (cin >> n) {
        lx = 10000, rx = -10000;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            if (y[i] == 0) {
                lx = min(lx, x[i]);
                rx = max(rx, x[i]);
            }
        }
        x[n] = x[0], y[n] = y[0];
        A = 0, T = 0;
        for (int i = 0; i < n; ++i) {
            A += x[i] * y[i + 1] - y[i] * x[i + 1];
            T += (x[i] + x[i + 1]) * (x[i] * y[i + 1] - y[i] * x[i + 1]);
        }
        A /= 2.0;
        if (A < 0.0) {
            A = -A, T = -T;
        }
        cx = T / (6 * A);
        if (x[0] < cx) {
            x[0] = -x[0], cx = -cx;
            swap(lx, rx);
            lx = -lx, rx = -rx;
        }
        if (cx > rx || lx >= x[0]) {
            cout << "unstable" << '\n';
        } else {
            if (lx <= cx) {
                cout << 0;
            } else {
                cout << fl(A * (lx - cx) / (x[0] - lx));
            }
            cout << " .. ";
            if (x[0] <= rx) {
                cout << "inf";
            } else {
                cout << ce(A * (rx - cx) / (x[0] - rx));
            }

            cout << '\n';
        }
    }

    return 0;
}