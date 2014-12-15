#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>


#define X first
#define Y second


using namespace std;


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int binom[200][200], n, k;

    binom[0][0] = 1;
    binom[1][0] = 1;
    binom[1][1] = 1;

    for (int n = 2; n < 200; n += 1) {
        binom[n][0] = 1;
        binom[n][n] = 1;
        for (int r = 1; r <= n / 2; r += 1) {
            binom[n][r] = (binom[n - 1][r] + binom[n - 1][r - 1]) % 1000000;
            binom[n][n - r] = binom[n][r];
        }
    }

    while (cin >> n >> k && (n + k)) {
        cout << binom[n + k - 1][k - 1] << '\n';
    }

    return 0;
}















