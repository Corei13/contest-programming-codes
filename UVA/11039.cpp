#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 12000
#define x first
#define y second

int T, N, y[2], A;
pair<int, int> a[501000];

int main() {
    cin >> T;

    for (int t = 0; t < T; t += 1) {
        cin >> N;

        for (int i = 0; i < N; i += 1) {
            cin >> a[i].x;
            a[i].y = (a[i].x < 0);
            a[i].x = abs(a[i].x);
        }

        sort(a, a + N);

        A = 1;

        for (int i = 1; i < N; i += 1) {
            if (a[i].y != a[i - 1].y)
                A++;
        }

        cout << A << '\n';
    }

    return 0;
}

