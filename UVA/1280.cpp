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

int n, cs;
double a[32], b[32];
double _lo, lo, hi, inc, V;
vector <double> v;

double f ( double x )
{
    double r = 0.0;
    for (int i = n; i >= 0; i -= 1)
        r = r*x + a[i];
    return r*x;
}

double R ( double x )
{
    return int(x*100.0+0.5+1e-6)/100.0;
}   

int main()
{
    while ( cin >> n )
    {
        for (int i = 0; i <= 2*n; i += 1)
            a[i] = 0, b[i] = 0;
        for (int i = 0; i <= n; i += 1)
            cin >> b[i];
        for (int i = 0; i <= 2*n; i += 1)
            for (int j = 0; j <= i; j += 1)
                a[i] += b[j]*b[i-j];
        n *= 2;
        for (int i = 0; i <= n; i += 1)
            a[i] *= acos(-1)/double(i+1);
        cin >> lo >> hi >> inc;
        V = f(hi)-f(lo);
        cout << "Case " << ++cs << ": ";
        printf("%.2lf\n",R(V));
        if (inc > V)
        {
            cout << "insufficient volume\n";
        }
        else
        {
            v.clear();
            double p;
            _lo = lo;
            double dis = f(lo) + inc;
            while ( dis <= f(hi) && int(v.size()) < 8 )
            {
                double p;
                for (double x = lo+0.0001; ; x += 0.0001)
                {
                    if (fabs(f(x)-dis) <= fabs(f(x-0.0001)-dis))
                        p = x;
                    else
                        break;
                }
                lo = p;
                v.push_back(lo);
                dis += inc;
            }
            printf("%.2lf",R(v[0]-_lo));
            for (int i = 1; i < v.size(); i += 1)
                printf(" %.2lf",R(v[i]-_lo));
            cout << '\n';
        }
    }
        
    return 0;
}
