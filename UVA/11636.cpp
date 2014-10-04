#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 12000
#define x first
#define a second.first
#define b second.second

int T, N;

int main()
{
    while(cin >> N && N > 0)
    {
        cout << "Case " << ++T << ": " << (int)(ceil(log2(N))) << '\n';
    }
        
    return 0;
}
