#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

#define MAXN 10005
#define X first
#define Y second


using namespace std;


const int inf = 2000000000;

int N;
int I[MAXN];

vector <int> LIS( int S[], int n ) {
    vector <int> L(MAXN);
    I[0] = -inf; // I[0] = -infinite
    for ( int i = 1; i <= n; i++ )
        I[i] = inf;

    int LisLength = 0;

    for ( int i = 0; i < n; i++ ) {
        int low, high, mid;
        low = 0;
        high = LisLength;

        while ( low <= high ) {
            mid = ( low + high ) / 2;
            if ( I[mid] < S[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }

        I[low] = S[i];
        L[i] = low;
        if ( LisLength < low )
            LisLength = low;
    }

    return L;
}


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int W, S[MAXN], T[MAXN];
    vector<int> a, b;

    while (cin >> N) {
        for (int i = 0; i < N; i += 1) {
            cin >> S[i];
            T[N - 1 - i] = S[i];
        }
        a = LIS(S, N);
        b = LIS(T, N);
        W = 0;
        for (int i = 0; i < N; i += 1) {
            W = max(W, 2 * min(a[i], b[N - 1 - i]) - 1);
        }
        cout << W << '\n';
    }

    return 0;
}



