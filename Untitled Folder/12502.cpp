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

int T;
int x, y, z;

int main (int argc, char const *argv[]) {
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        cin >> x >> y >> z;
        cout << max( 0, min( z, z * (2 * x - y) / (x + y) ) ) << '\n';
    }


    return 0;
}















