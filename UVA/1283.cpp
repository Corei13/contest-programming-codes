#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include <sstream>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAXN 100500
#define pi pair <int, int>
#define y first
#define x second
using namespace std;

typedef vector < int > VI;
typedef vector < VI > VVI;

int N, cs, cnt;
char ch;
VVI x;
int sid = 200000;
VI a, e;
int l, st;

void find ( int n = 1 )
{
    a = VI(n);
    for (int s = 0; s < sid; s += 1)
    {
        e = VI(N+1,0);
        st = 0;
        for (int i = 0; i < n; i += 1)
        {
            a[i] = st+1+rand()%(N-st);
            st = a[i];
            e[st] = 1;
            if(st == N)
            {
                l = 1;
                for (int j = i+1; j < n; j += 1)
                {
                    for (; l <= N; l += 1)
                    {
                        if(!e[l])
                        {
                            a[j] = l;
                            l++;
                            break;
                        }
                    }
                }
                break;
            }
        }
        cnt = 0;
        for (int k = 1; k <= N; k += 1)
        {
            l = 0;
            for (int j = 0; j < n; j += 1)
            {
                l |= x[a[j]][k];
            }
            cnt += l;
        }
        if (cnt == N)
        {
            cout << n;
            for (int i = 0; i < n; i += 1)
            {
                cout << ' '  << a[i];
            }
            cout << '\n';
            return;
        }
    }
    find(n+1);
}


int main()
{
    srand(time(NULL));
    while ( cin >> N )
    {
        x = VVI(N+1,VI(N+1));
        for (int i = 1; i <= N; i += 1)
            for (int j = 1; j <= N; j += 1)
                {cin >> ch; x[i][j] = ch-'0';}
        for (int i = 1; i <= N; i += 1)
            x[i][i] = 1;
        cout << "Case " << ++cs << ": ";
        find();
    }
        
    return 0;
}

