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

    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int A, B, n;
        cin >> A >> B >> n;
        vector <int> a(n), b(n), index(n);
        vector <string> name(n);
        for (int i = 0; i < n; ++i) {
            index[i] = i;
            cin >> name[i];
            while (name[i].back() != ':') {
                cin.putback(name[i].back());
                name[i].pop_back();
            }
            name[i].pop_back();
            cin >> a[i];
            cin.ignore();
            cin >> b[i];
        }
        auto cost = [&A, &B] (int a, int b) {
            int ret = 0, curr = A;
            while (curr / 2 >= B) {
                ret += min(a * (curr - curr / 2), b);
                curr /= 2;
            }
            ret += a * (curr - B);
            return ret;
        };
        sort (all(index), [&a, &b, &cost, &name] (int i, int j) {
            return make_pair(cost(a[i], b[i]), name[i]) < make_pair(cost(a[j], b[j]), name[j]);
        });
        print("Case", cs + 1);
        for (auto i : index) {
            print(name[i], cost(a[i], b[i]));
        }
    }

    return 0;
}
