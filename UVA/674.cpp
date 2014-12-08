#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>

#define X first
#define Y second


using namespace std;


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int ans[7500];
    int c[] = {1, 5, 10, 25, 50};

    for (int i = 0; i < 7500; i += 1) {
        ans[i] = 1;
    }

    for (int i = 1; i < 5; i += 1) {
        for (int n = c[i]; n < 7500; n += 1) {
            ans[n] += ans[n - c[i]];
            //cout << n << ' ' << n-c[i] << ' ' << ans[n] << '\n';
        }
    }


    int n;
    while (cin >> n) {
        cout << ans[n] << '\n';
    }


    return 0;
}















