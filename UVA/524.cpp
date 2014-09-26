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
typedef vector <bool> VB;
typedef vector <long double> VD;
typedef vector <VD> VVD;

void backtrack (int i, int n, int mask, VI &a, VB &isPrime) {
    if (i == n) {
        if (isPrime[a.front() + a.back()]) {
            for (int j = 0; j < n; ++j) {
                cout << a[j] << ( j + 1 == n ? "\n" : " " );
            }
        }
    } else {
        for (int j = 0; j < n; ++j) if (!(mask & (1 << j)) && isPrime[a.back() + j + 1]) {
            a.push_back(j + 1);
            backtrack(i + 1, n, mask | (1 << j), a, isPrime);
            a.pop_back();
        }
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    VB isPrime(32, false);
    for (int n = 2; n < 32; ++n) {
        isPrime[n] = true;
        for (int i = 2; i < n; ++i) if (n % i == 0) {
            isPrime[n] = false;
        }
    }

    int n, cs = 0;
    while (cin >> n) {
        VI a;
        a.push_back(1);
        if (cs != 0)    cout << endl;
        cout << "Case " << ++cs << ":" << endl;
        backtrack(1, n, 1, a, isPrime);
    }
    
    return 0;
}
