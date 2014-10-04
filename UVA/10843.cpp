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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

const ll mod = 2000000011LL;

template <ll a, ll b>
struct Pow {
    static const ll value = (((Pow<a, b/2LL>::value * Pow<a, b/2LL>::value) % mod) * (b % 2LL == 1 ? a : 1LL)) % mod;
    
};

template <ll a>
struct Pow<a, 0> {
    static const ll value = 1;
};

template <ll a>
struct Pow<a, -1> {
    static const ll value = 1;
};

template <ll n>
struct Anne {
    static const ll value = Pow<n, n-2>::value;
};

int anne[100] = {
    Anne<  1>::value, Anne<  2>::value, Anne<  3>::value, Anne<  4>::value, Anne<  5>::value, Anne<  6>::value, Anne<  7>::value, Anne<  8>::value, Anne<  9>::value, Anne< 10>::value,
    Anne< 11>::value, Anne< 12>::value, Anne< 13>::value, Anne< 14>::value, Anne< 15>::value, Anne< 16>::value, Anne< 17>::value, Anne< 18>::value, Anne< 19>::value, Anne< 20>::value,
    Anne< 21>::value, Anne< 22>::value, Anne< 23>::value, Anne< 24>::value, Anne< 25>::value, Anne< 26>::value, Anne< 27>::value, Anne< 28>::value, Anne< 29>::value, Anne< 30>::value,
    Anne< 31>::value, Anne< 32>::value, Anne< 33>::value, Anne< 34>::value, Anne< 35>::value, Anne< 36>::value, Anne< 37>::value, Anne< 38>::value, Anne< 39>::value, Anne< 40>::value,
    Anne< 41>::value, Anne< 42>::value, Anne< 43>::value, Anne< 44>::value, Anne< 45>::value, Anne< 46>::value, Anne< 47>::value, Anne< 48>::value, Anne< 49>::value, Anne< 50>::value,
    Anne< 51>::value, Anne< 52>::value, Anne< 53>::value, Anne< 54>::value, Anne< 55>::value, Anne< 56>::value, Anne< 57>::value, Anne< 58>::value, Anne< 59>::value, Anne< 60>::value,
    Anne< 61>::value, Anne< 62>::value, Anne< 63>::value, Anne< 64>::value, Anne< 65>::value, Anne< 66>::value, Anne< 67>::value, Anne< 68>::value, Anne< 69>::value, Anne< 70>::value,
    Anne< 71>::value, Anne< 72>::value, Anne< 73>::value, Anne< 74>::value, Anne< 75>::value, Anne< 76>::value, Anne< 77>::value, Anne< 78>::value, Anne< 79>::value, Anne< 80>::value,
    Anne< 81>::value, Anne< 82>::value, Anne< 83>::value, Anne< 84>::value, Anne< 85>::value, Anne< 86>::value, Anne< 87>::value, Anne< 88>::value, Anne< 89>::value, Anne< 90>::value,
    Anne< 91>::value, Anne< 92>::value, Anne< 93>::value, Anne< 94>::value, Anne< 95>::value, Anne< 96>::value, Anne< 97>::value, Anne< 98>::value, Anne< 99>::value, Anne<100>::value
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        ll n;
        cin >> n;
        cout << "Case #" << cs + 1 << ": " << anne[n-1] << endl;
    }
    
    return 0;
}