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
#define forall(i,n) for( int i = 0; i < n; ++i )
#define pb push_back
#define mp make_pair

using namespace std;

int N, L, T, p[512];
string S;
unsigned char ch;

int main (int argc, char const *argv[]) {
    cin >> T;

    for (int t = 0; t < T; t += 1) {
        memset(p, 0, sizeof(p));
        cin >> N;

        for (int i = 0; i < N; i += 1) {
            cin >> ch >> L;
            p[(unsigned char)ch] = L;
        }

        cin >> L;
        getline(cin, S);
        int Tot = 0;

        for (int i = 0; i < L; i += 1) {
            getline(cin, S);
            for (int j = 0; j < S.size(); j += 1) {
                Tot += p[(unsigned char)S[j]];
            }
        }

        cout << Tot / 100 << '.';
        Tot %= 100;
        if (Tot < 10) {
            cout << 0;
        }
        cout << Tot << "$\n";
    }

    return 0;
}













