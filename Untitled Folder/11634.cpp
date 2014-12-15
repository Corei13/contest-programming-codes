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

int N, A;
int cnt[10500];


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    while ( cin >> N && N ) {
        memset ( cnt, 0, sizeof(cnt) );
        A = 0;

        while ( cnt[N] == 0 ) {
            cnt[N] = 1;
            N *= N;
            N /= 100;
            N %= 10000;
            A++;
        }
        cout << A << '\n';
    }

    return 0;
}












