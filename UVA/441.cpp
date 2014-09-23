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

typedef vector <string> VS;
typedef vector <long double> VD;
typedef vector <VD> VVD;

void backtrack (int curr, int k, VI &seq, VI &s) {
    if (sz(seq) == k) {
        for (int i = 0; i < k; ++i) {
            cout << s[seq[i]] << (i + 1 == k ? "\n" : " ");
        }
        return;
    }
    
    for (int i = curr; i < sz(s); ++i) {
        seq.push_back(i);
        backtrack(i + 1, k, seq, s);
        seq.pop_back();
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, cs = 0;
    while (cin >> n && n != 0) {
        if (cs++ != 0) {
            cout << endl;
        }
        VI s(n);
        for (auto &a: s) {
            cin >> a;
        }
        VI seq;
        backtrack(0, 6, seq, s);
    }
    
    return 0;
}
