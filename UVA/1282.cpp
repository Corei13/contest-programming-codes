#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include <sstream>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 100500
#define pi pair <int, int>
#define y first
#define x second

using namespace std;

int N, _n, cs, tr, u;
int chk[MAXN][128], pre[MAXN], suf[MAXN];
long long A[128], B[128], F[128];
string s;

int bS ( long long n, int lo = 1, int hi = 100 ) // first i s.t. F[i] >= n
{
    if (lo == hi)
    {
        if (F[lo] >= n)
        {
            return lo;
        }
        else return lo+1;
    }
    if (lo + 1 == hi)
    {
        if (F[lo] >= n)
        {
            return lo;
        }
        if (F[hi] >= n)
        {
            return hi;
        }
        return hi+1;
    }
    int mid = (hi+lo)/2;
    if (F[mid] >= n)
    {
        return bS(n,lo,mid);
    }
    return bS(n,mid+1,hi);
}
int check ( int i, int n )
{
    if ( chk[i][n] != -1 )
        return chk[i][n];
    if ( F[n] > N-i )
    {
        return chk[i][n] = 0;
    }
    if (n == 0)
    {
        return chk[i][0] = (s[i] == '0');
    }
    if (n == 1)
    {
        return chk[i][1] = (s[i] == '1');
    }
    chk[i][n] = 0;
    if (check(i,n-1))
    {
        if (check(i+F[n-1],n-2))
        {
            chk[i][n] = 1;
        }
    }
    return chk[i][n];
}

int Pre ( int i, int n )
{
    if(n == 0)
    {
        return ( i == N-1 && s[i] == '0');
    }
    return pre[i] <= n;
}

int Suf ( int i, int n )
{
    if(n == 0)
    {
        return ( i == 0 && s[i] == '0');
    }
    return suf[i] <= n && (suf[i]%2 == n%2);
}
long long find ( int n )
{
    if ( A[n] != -1 )
        return A[n];
    if ( n == 0 )
    {
        A[0] = (s == "0");
        return A[0];
    }
    if ( n == 1 )
    {
        A[1] = (s == "1");
        return A[1];
    }
    
    A[n] = find(n-1)+find(n-2);
    B[n] = 0;
    if (n >= 4 && N <= F[n-4])
        B[n] = B[n-2];
    else
        for (int i = 0; i < N-1; i += 1)
            B[n] += (long long)(Suf(i,n-1)&Pre(i+1,n-2));
    A[n] += B[n];
    return A[n];
}

int main()
{
    F[0] = 1;
    F[1] = 1;
    for (int n = 2; n < 128; n += 1)
        F[n] = min(F[n-1]+F[n-2],1000000000LL);
    while ( cin >> _n >> s )
    {
        N = s.size();
        for (tr = 0; F[tr] < (long long)N; tr += 1);
        tr += tr&1;
        tr = 10;
        
        memset(chk,-1,sizeof(chk));

        suf[0] = s[0]-'0';
        for (int i = 1; i < N; i += 1)
        {
            u = bS(i+1);
            if (u < 2)
            {
                suf[i] = (s[0] == '1')? u : 1000;
            }
            else
            {
                suf[i] = (Suf(i-F[u-2],u-1) && check(i-F[u-2]+1,u-2))?u:1000;
            }
            u++;
            if (u < 2)
            {
                suf[i] = min(suf[i], (s[0] == char(u+'0'))? u : 1000);
            }
            else
            {
                suf[i] = min(suf[i], (Suf(i-F[u-2],u-1) && check(i-F[u-2]+1,u-2))?u:1000);
            }
        }

        for (int i = N-1; i >= 0; i -= 1)
        {
            u = bS(N-i);
            if (u < 2)
            {
                pre[i] = (s[N-1] == char(u+'0'))? u : 1000;
            }
            else
            {
                pre[i] = (Pre(i+F[u-1],u-2) && check(i,u-1))?u:1000;
            }
        }
        
        for (int i = 0; i <= _n; i += 1)
            A[i] = -1;
        cout << "Case " << ++cs << ": " << find(_n) << '\n'; 
        
    }
        
    return 0;
}
