#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <queue>
#include <deque>
#include <fstream>
#include <set>
#include <map>



#define MAXN 100005

#define pi pair <int, int>
#define Point pair <double, double>
#define data pair <string, double>
#define vi vector < int >
#define vvi vector < vi >
#define X first
#define Y second
#define all(v) (v).begin(), (v).end()
#define forall(i,n) for( int (i) = 0; (i) < (n); ++(i) )
#define pb push_back
#define mp make_pair

using namespace std;

int N, T, a[4], n, mod;
string S;

int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    cin >> T;

    for (int t = 0; t < T; t += 1) {
        cin >> S;

        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        mod = 0;

        for (int i = 0; i < S.size(); i += 1) {
            n = int(S[i] - '0');
            mod = ( mod + n ) % 3;
            a[n % 3]++;;
        }

        cout << "Case " << t + 1 << ": ";

        if ( a[mod] == 0 ) {
            cout << "T\n";
        } else {
            a[mod]--;

            if ( a[0] & 1 ) {
                cout << "T\n";
            } else    cout << "S\n";
        }
    }

    return 0;
}












