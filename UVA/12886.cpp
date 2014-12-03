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

void build (int a, int b, int c, vector <vector <bool>>& s, vector <vector <ll>>& t, ll B, ll M) {
    t = vector <vector <ll>> (a - c + 1, vector <ll> (b));

    for (int i = 0; i < b; ++i) {
        t[0][i] = 0;
        for (int j = 0; j < c; ++j) {
            t[0][i] = (t[0][i] * B + int(s[j][i])) % M;
        }
    }
    ll tmp = 1;
    for (int i = 1; i < c; ++i) {
        tmp = (tmp * B) % M;
    }
    for (int k = 1; k <= a - c; ++k) {
        for (int i = 0; i < b; ++i) {
            t[k][i] = ((t[k - 1][i] - int(s[k - 1][i]) * tmp) * B + int(s[k + c - 1][i])) % M;
            t[k][i] = (t[k][i] + M) % M;
        }
    }
}

void buildTable(int n, vector <ll>& pattern, vector <int>& t) {
    t = vector <int>(n);
    int i = 2, j = 0;
    t[0] = -1, t[1] = 0;

    while (i < n) {
        if (pattern[i - 1] == pattern[j]) {
            t[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) j = t[j];
        else {
            t[i] = 0;
            i++;
        }
    }
}

int KMP (int n, int N, vector <ll>& pattern, vector <ll>& image) {
    int m = 0, i = 0, ret = 0;
    vector <int> t;
    buildTable(n, pattern, t);

    while (m + i < N) {
        if (pattern[i] == image[m + i]) {
            i++;
            if (i == n) {
                ret++, i = 0, m++;
            }
        } else {
            m += i - t[i];
            if (i > 0) {
                i = t[i];
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    ll B, M;
    do {
        B = 100000000LL + rand () % 100000000LL;
        M = 100000000LL + rand () % 100000000LL;
    } while (__gcd(B, M) != 1);

    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        if (c < a || d < b) {
            cout << 0 << endl;
            continue;
        }
        vector <vector <bool>> small (a), big(c);
        vector <vector <ll>> pattern, image;

        for (int i = 0; i < a; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < b; ++j) {
                small[i].push_back(s[j] == 'x');
            }
        }

        for (int i = 0; i < c; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < d; ++j) {
                big[i].push_back(s[j] == 'x');
            }
        }

        int ans = 0;
        build(a, b, a, small, pattern, B, M);
        build(c, d, a, big, image, B, M);
        for (auto& row : image) {
            ans += KMP (b, d, pattern[0], row);
        }
        cout << ans << endl;

    }

    return 0;
}