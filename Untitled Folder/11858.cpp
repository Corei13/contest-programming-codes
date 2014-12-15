//#include <iostream>
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

int tree[1000500], num[1000500], a, N;

int query(int a, int b) {
    if (a == 0) {
        int sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1)
            sum += tree[b];
        return sum;
    } else {
        return query(0, b) - query(0, a - 1);
    }
}

void increase(int k) {
    for (; k < N; k |= k + 1)
        tree[k]++;
}

long long A;
pair<int, int> u;
vector<pair<int, int>> s;

bool comp ( pair<int, int> a, pair<int, int> b ) {
    return a.X < b.X;
}

int main (int argc, char const *argv[]) {
    while ( scanf("%d", &N) != EOF ) {
        memset ( tree, 0, sizeof(tree) );
        A = 0;
        s.clear();

        for (int i = 0; i < N; i += 1) {
            scanf ( "%d", &a );
            s.pb(mp(a, i));
        }

        sort(all(s), comp);

        for (int i = 0; i < N; i += 1) {
            num[s[i].Y] = N - i - 1;
        }

        for (int i = 0; i < N; i += 1) {
            A = A + (long long)query(0, num[i]);
            increase(num[i]);
        }

        printf("%lld\n", A);
    }

    return 0;
}













