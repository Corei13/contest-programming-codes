#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <deque>
#include <map>


using namespace std;

#define MAXN 16384
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;
typedef vector<double> VD;
typedef vector<VD> VVD;

int n;
int v[MAXN];
int idx[MAXN];
VI a;

int comp ( int a, int b )
{
    return idx[a] < idx[b];
}

int main (int argc, char const* argv[])
{
    v[0] = 0;
    for (int i = 0; i < 14; i += 1)
        for (int j = 0; j < (1<<i); j += 1)
            v[j] <<= 1, v[j|(1<<i)] = v[j]+1;
    
    for (int i = 0; i < MAXN; i += 1)
        idx[v[i]] = i;
        
    while (cin >> n && n)
    {
        a = VI(n);
        for (int i = 0; i < n; i += 1)
            a[i] = i;
        sort(all(a), comp);
        
        cout << n << ":";
        for (int i = 0; i < n; i += 1)
        {
            cout << ' ' << a[i];
        }
        cout << '\n';
    }
    
    return 0;
}
