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

void divisor(int N, VI &d) {
    for (int i = 1; i*i <= N; ++i) if (N % i == 0) {
        d.pb(i);
        if (i * i != N)  d.pb(N / i);
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n && n != 0) {
        int N = 0;
        VI x(n);
        for (int i = 0; i < n; ++i) {
           cin >> x[i];
           N += x[i];
           x[i] = N;
        }
        VI d;
        divisor(N, d);
        sort(all(d));
        int ans = -1;
        for (int i = sz(d) - 1; d[i] >= 3 && i >= 0 && ans == -1; i--) {
            map <int, int> cnt;
            for (int j = 0; j < n; ++j) {
                cnt[x[j] % (N/d[i])] = cnt[x[j] % (N/d[i])] + 1;
            }
            for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) if (it->y == d[i]) {
                ans = n - d[i];
                break;
            }   
        }
        cout << ans << endl;
    }

    return 0;
}
