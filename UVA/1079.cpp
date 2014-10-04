#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include <sstream>
#include <queue>

using namespace std;

#define MAXN 12000
#define pi pair <int, int>
#define y first
#define x second

using namespace std;


int N, A, mm, ss, cs, u[8];
pi a[8];

int check ( int s )
{
    int x = a[u[0]].x;
    for (int i = 1; i < N; i += 1)
    {
        if ( max(x + s,a[u[i]].x) <= a[u[i]].y )
            x = max(x + s,a[u[i]].x);
        else return 0;
    }
    return 1;
}

int find ( int lo = 0, int hi = 1440*60*100 )
{
    if (lo == hi)
    {
        if (check(lo))
            return lo;
        return lo-1;
    }
    if (lo+1 == hi)
    {
        if (check(hi))
            return hi;
        if (check(lo))
            return lo;
        return lo-1;
    }

    int mid = (lo+hi)/2;

    if (check(mid))
        return find(mid+1,hi);
    return find(lo,mid-1);
}

int main()
{
    while (cin >> N && N)
    {
        for (int i = 0; i < N; i += 1) {
            cin >> a[i].x >> a[i].y;
            a[i].x *= 6000;
            a[i].y *= 6000;
            u[i] = i;
        }
        A = 0;
        do
        {
            A = max(find(),A);
        } while ( next_permutation(u,u+N) );
        
        A = int(A/100.0 + 0.5);
        mm = A / 60;
        ss = A%60;
        cout << "Case " << ++cs << ": " << mm << ":";
        if(ss < 10)
            cout << 0;
        cout << ss << "\n";
    }
        
    return 0;
}