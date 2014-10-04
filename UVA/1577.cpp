#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <deque>

using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%M)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;

int N, K, D;
VI x;

int check ( int d )
{
    int r = 0;
    for (int i = 0; i < 2*N*K; i += 1)
    {
        if ( i <= 2*r*K && x[i+1]-x[i] <= d )
        {
            r++;
            i++;
            if( r == N )
                return 1;
        }
        else if ( i > 2*r*K )
            return 0;
    }
}

int find ( int lo = 0, int hi = D )
{
    if(hi == lo)
        return lo;
    int mid = lo+(hi-lo)/2;
    
    if (check(mid))
        return find(lo,mid);
    else
        return find(mid+1,hi);
}

int main (int argc, char const* argv[])
{
    ios::sync_with_stdio(false);
    
    while (cin >> N >> K) {
        x = VI(2*N*K);
        for (int i = 0; i < 2*N*K; i += 1)
             cin >> x[i];
            
        sort(all(x));
        D = 0;
        for (int i = 0; i < 2*N*K-1; i += 1)
            D = max(D, x[i+1]-x[i]);
        
        cout << find() << '\n';
    }
        
    return 0;
}






