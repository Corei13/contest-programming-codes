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
typedef vector<string> VS;
typedef pair<int, ll> PI;
typedef vector<PI> VPI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

template <int n> struct ans {
    const static ll a = 3LL * ans < n - 1 >::a + 2LL * ans < n - 1 >::b, b = 4LL * ans < n - 1 >::a + 3LL * ans < n - 1 >::b;
};
template <> struct ans <0> {
    const static ll a = 12, b = 17;
};

int main(int argc, char const *argv[]) {
    printf("%10lld%10lld\n", ans<0>::a / 2LL, ans<0>::b / 2LL);
    printf("%10lld%10lld\n", ans<1>::a / 2LL, ans<1>::b / 2LL);
    printf("%10lld%10lld\n", ans<2>::a / 2LL, ans<2>::b / 2LL);
    printf("%10lld%10lld\n", ans<3>::a / 2LL, ans<3>::b / 2LL);
    printf("%10lld%10lld\n", ans<4>::a / 2LL, ans<4>::b / 2LL);
    printf("%10lld%10lld\n", ans<5>::a / 2LL, ans<5>::b / 2LL);
    printf("%10lld%10lld\n", ans<6>::a / 2LL, ans<6>::b / 2LL);
    printf("%10lld%10lld\n", ans<7>::a / 2LL, ans<7>::b / 2LL);
    printf("%10lld%10lld\n", ans<8>::a / 2LL, ans<8>::b / 2LL);
    printf("%10lld%10lld\n", ans<9>::a / 2LL, ans<9>::b / 2LL);
    return 0;
}