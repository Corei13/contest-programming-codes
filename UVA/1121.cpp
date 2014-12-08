#include <iostream>
#include <deque>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

#define pi pair <int, int>
#define x first
#define y second
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define all(v) (v).begin(), (v).end()

using namespace std;

int N, A, S, a[100500], cnt;


int main (int argc, char const *argv[]) {

    while ( cin >> N >> S ) {
        A = N + 1;
        cnt = 0;
        for (int i = 1; i <= N; i += 1) {
            cin >> a[i];
            a[i] += a[i - 1];
            while (a[i] - a[cnt] >= S)
                A = min(A, i - cnt++);
        }

        cout << A % (N + 1) << '\n';
    }



    return 0;
}















