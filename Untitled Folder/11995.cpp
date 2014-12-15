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
#define forall(i,n) for( int i = 0; i < n; ++i )
#define pb push_back
#define mp make_pair

using namespace std;

multiset<int> PQ;
deque<int> ST, Q;
int N, a, b, c, isPQ, isST, isQ;

int main (int argc, char const *argv[]) {
    while ( scanf("%d", &N) != EOF ) {
        isPQ = 1, isST = 1, isQ = 1;
        PQ.clear();
        ST.clear();
        Q.clear();

        for (int i = 0; i < N; i += 1) {
            scanf("%d %d", &a, &b);
            if (a == 1) {
                PQ.insert(-b);
                ST.pb(b);
                Q.pb(b);
            } else {
                if (!PQ.empty()) {
                    c = *PQ.begin();
                    PQ.erase(PQ.begin());
                    c = -c;
                    if (c != b) {
                        isPQ = 0;
                    }
                } else    isPQ = 0;

                if (!ST.empty()) {
                    c = ST.back();
                    ST.pop_back();
                    if (c != b) {
                        isST = 0;
                    }
                } else    isST = 0;

                if (!Q.empty()) {
                    c = Q.front();
                    Q.pop_front();
                    if (c != b) {
                        isQ = 0;
                    }
                } else    isQ = 0;

            }
        }

        if (isPQ + isST + isQ > 1) {
            printf("not sure\n");
        } else if (isPQ + isST + isQ == 0) {
            printf("impossible\n");
        } else if (isPQ) {
            printf("priority queue\n");
        } else if (isST) {
            printf("stack\n");
        } else    printf("queue\n");
    }

    return 0;
}













