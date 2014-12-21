#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VS = vector<string>;
using PI = pair<int, int>;
using VPI = vector<PI>;
using VVPI = vector<VPI>;
using VD = vector<double>;
using VVD = vector<VD>;

template <typename Head>
constexpr void print (Head&& head) {
    cout << head << endl;
}
template <typename Head, typename... Tail>
constexpr void print (Head&& head, Tail&& ... tail) {
    cout << head << ' ';
    print(tail...);
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    do {
        vector <int> w(8);
        vector <int> x { -1, 0, 1, -1, 1, -1, 0, 1 };
        vector <int> y { 1, 1, 1, 0, 0, -1, -1, -1 };
        bool allzero = true;
        for (int i = 0; i < 8; ++i) {
            cin >> w[i];
            allzero = allzero and (w[i] == 0);
        }
        if (allzero) {
            break;
        } else {
            sort(all(w));
            double ans = numeric_limits<double>::max();
            do {
                int Mx = inner_product(all(w), x.begin(), 0);
                int My = inner_product(all(w), y.begin(), 0);
                ans = min (ans, sqrt (double(Mx * Mx + My * My)));
            } while (next_permutation(all(w)));
            cout << fixed << setprecision(3) << ans << endl;
        }
    } while (true);

    return 0;
}
