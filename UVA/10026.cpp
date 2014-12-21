#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

using namespace std;

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

template <typename T, typename F>
constexpr void print (const T& container, const F&& func = [](int i) {
    return i;
}) {
    for (auto first = container.begin(); first != container.end();) {
        cout << func(*first);
        first++;
        if (first != container.end()) {
            cout << ' ';
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        vector <int> d(n), s(n);
        vector <int> index (n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i] >> s[i];
            index[i] = i;
        }
        sort(all(index), [&d, &s] (int i, int j) {
            return make_pair(d[i] * s[j], i) < make_pair(d[j] * s[i], j);
        });
        if (cs) {
            cout << endl;
        }
        print (index, [](int i) {
            return i + 1;
        });
    }

    return 0;
}
