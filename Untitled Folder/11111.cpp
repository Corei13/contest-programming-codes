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

long long N;
int cnt[1000500];
vector <int> v;
int sz, a;
string S;

int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    while ( getline ( cin, S ) ) {
        stringstream ss(S);
        v.clear();
        sz = -1;
        bool finish = false;
        bool flag = true;

        while ( ss >> a ) {
            if (finish) {
                flag = false;
                break;
            }
            if ( a < 0 ) {
                v.push_back(-a);
                sz++;
                cnt[sz] = 0;
            } else {
                if (v.empty()) {
                    flag = false;
                } else if ( cnt[sz] >= v.back() || a != v.back() ) {
                    flag = false;
                } else {
                    v.pop_back();
                    sz--;
                    if (sz < 0) {
                        finish = true;
                    } else    cnt[sz] += a;
                }
            }

        }

        if (flag && v.empty()) {
            cout << ":-) Matrioshka!\n";
        } else    cout << ":-( Try again.\n";
    }

    return 0;
}












