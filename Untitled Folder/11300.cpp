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

int N;
long long a[1024 * 1024], s[1024 * 1024];
unsigned long long T, A;


int main (int argc, char const *argv[]) {

    while ( cin >> N ) {
        T = 0;

        for (int i = 0; i < N; i += 1) {
            cin >> a[i];
            T += a[i];
        }

        T /= (unsigned long long)(N);
        //cout << T <<'\n';
        s[0] = 0;

        for (int i = 0; i < N; i += 1) {
            a[i] -= T;
            if (i)
                s[i] = s[i - 1] + a[i - 1];
            //cout << a[i] << ' ' << s[i] << '\n';
        }

        sort(s, s + N);
        A = 0;

        for (int i = 0; i < N; i += 1) {
            A += abs(-s[N / 2] + s[i]);
        }

        cout << A << '\n';
    }



    return 0;
}















