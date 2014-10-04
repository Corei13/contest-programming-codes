#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <deque>
#include <map>


using namespace std;

#define MAXN 1024*1024
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
VI a, b, c, d;
VVI dp;

int main (int argc, char const* argv[])
{
    while (cin >> n && n)
    {
        a = VI(n+1), b = VI(n+1), dp = VVI(n+1, VI(n+1, 0)), c = VI(n+1, 0), d = VI(n+1, 0);
        a[0] = -1, b[0] = -1;
        for (int i = 0; i < n; i += 1)
            cin >> a[i];
        for (int i = 0; i < n; i += 1)
            cin >> b[i];
        sort(all(a));
        sort(all(b));
        
        for (int i = 1; i <= n; i += 1)
        {
            for (int j = n; j > 0; j -= 1)
                if(b[j] <= a[i]) {
                    d[i] = j;
                    break;
                }
            for (int j = n; j > 0; j -= 1)
                if(b[j] < a[i]) {
                    c[i] = j;
                    break;
                }            
        }
        
        for (int i = 1; i <= n; i += 1)
        {
            for (int j = 1; j <= n; j += 1)
            {
                dp[i][j] = dp[i-1][j];
                int k = d[i];
                if(k)   dp[i][j] = max(dp[i][j], dp[i-1][min(j-1,k-1)]+1);
                k = c[i];
                if(k)   dp[i][j] = max(dp[i][j], dp[i-1][min(j-1,k-1)]+2);
            }
        }
        
        cout << (dp[n][n]-n)*200 << '\n';
    }
    
    return 0;
}






