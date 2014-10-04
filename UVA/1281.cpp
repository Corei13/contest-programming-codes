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

int N, E, A, cs, a, b;
int m[1<<20], src[32][1<<20], dst[32][1<<20], d[32][32], t[32][32];
vector <int> v[32];

int main()
{
    for (int i = 0; i < 20; i += 1)
        for (int n = 0; n < (1<<i); n += 1)
            m[n|(1<<i)] = m[n] + 1; 
    while ( cin >> N >> E )
    {
        for (int i = 0; i < N; i += 1)
            for (int j = 0; j < N; j += 1)
                t[i][j] = 1000000;
        for (int i = 0; i < E; i += 1)
        {
            cin >> a >> b;
            cin >> t[a][b];
            t[b][a] = t[a][b];
        }
        for (int i = 0; i < N; i += 1)
        {
            t[i][i] = 0;
        }

        for (int k = 0; k < N; k += 1)
          for (int i = 0; i < N; i += 1)
            for (int j = 0; j < N; j += 1)
              t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
        
        N -= 2;

        for (int i = 0; i <= N; i += 1)
            v[i].clear();

        for (int i = 0; i < (1<<N); i += 1)
        {
            v[m[i]].push_back(i);
            for (int j = 0; j < N; j += 1)
            {
                src[j][i] = 1000000;
                dst[j][i] = 1000000;
            }
        }
        for (int i = 0; i < N; i += 1)
        {
            src[i][(1<<i)] = t[0][i+1];
            dst[i][(1<<i)] = t[N+1][i+1];
            for (int j = 0; j < N; j += 1)
            {
                d[i][j] = t[i+1][j+1];
            }
        }

        if(N == 1)
        {
            A = 2*(t[0][1] + t[1][2]);
            goto hell;
        }

        for (int n = 2; n <= (N+1)/2; n += 1)
         for (int i = 0; i < N; i += 1)
          for (int j = 0; j < N; j += 1)
           for (int k = 0; k < v[n].size(); k += 1)
            if( (v[n][k]&(1<<i)) && (v[n][k]&(1<<j)) )
             src[i][v[n][k]] = min (src[i][v[n][k]],src[j][v[n][k]^(1<<i)]+d[j][i]);
        
        for (int n = 2; n <= (N+1)/2; n += 1)
         for (int i = 0; i < N; i += 1)
          for (int j = 0; j < N; j += 1)
           for (int k = 0; k < v[n].size(); k += 1)
            if( (v[n][k]&(1<<i)) && (v[n][k]&(1<<j)) )
             dst[i][v[n][k]] = min (dst[i][v[n][k]],dst[j][v[n][k]^(1<<i)]+d[j][i]);

        A = 1000000;

        for (int i = 0; i < v[N/2].size(); i += 1)
        {
            a = v[N/2][i];
            b = ((1<<N)-1)^a;
            int fr = 1000000, bk = 1000000;
            for (int i = 0; i < N; i += 1)
             if ( a&(1<<i) )
              for (int j = 0; j < N; j += 1)
               if (b&(1<<j))
                fr = min(fr,src[i][a]+d[i][j]+dst[j][b]), bk = min(bk,src[j][b]+d[i][j]+dst[i][a]);
            A = min(A,fr+bk);
        }
        hell:
        cout << "Case " << ++cs << ": " << A << "\n";
    }
        
    return 0;
}
