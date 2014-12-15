#include <iostream>
#include <deque>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

#define pi pair <int, int>
#define x first
#define y second
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define all(v) (v).begin(), (v).end()

using namespace std;

int T;
int N;
int x[16][16], y[16][16], a;

int Y ( int i, int j ) {
    return ( i >= 0 && i < N && j >= 0 && j < N ) ? y[i][j] : 0;
}

int find ( int b ) {
    for (int i = 0; i < N; i += 1)
        y[0][i] = (b >> i) & 1;
    for (int i = 1; i < N; i += 1)
        for (int j = 0; j < N; j += 1)
            y[i][j] = (Y(i - 2, j) + Y(i - 1, j - 1) + Y(i - 1, j + 1)) & 1;
    for (int i = 0; i < N; i += 1)
        if ((Y(N - 1, i - 1) + Y(N - 1, i + 1) + Y(N - 2, i)) & 1)
            return N * N + 1;

    for (int i = 0; i < N; i += 1)
        for (int j = 0; j < N; j += 1)
            if (y[i][j] < x[i][j])
                return N * N + 1;

    int ret = 0;

    for (int i = 0; i < N; i += 1)
        for (int j = 0; j < N; j += 1)
            ret += y[i][j] - x[i][j];
    return ret;
}


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> T;

    for (int ts = 1; ts <= T; ts += 1) {
        cin >> N;

        for (int i = 0; i < N; i += 1) {
            for (int j = 0; j < N; j += 1) {
                cin >> x[i][j];
            }
        }

        if (N == 1) {
            cout << "Case " << ts << ": " << 0 << '\n';
            continue;
        }

        for (int i = 0; i < N; i += 1) {
            a |= (x[0][i] << i);
        }

        int A = N * N + 1;

        for (int i = 0; i < (1 << N); i += 1) {
            if ( i | a == i ) {
                A = min ( find(i), A );
            }
        }

        cout << "Case " << ts << ": " << ((A <= N * N) ? A : -1) << '\n';
    }

    return 0;
}















