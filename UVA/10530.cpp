#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>



#define X first
#define Y second


using namespace std;


int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    bool high[11], low[11];
    int N;
    string s[2];

    while (cin >> N && N > 0) {
        for (int i = 0; i < 11; i += 1) {
            low[i] = false;
            high[i] = false;
        }
        do {
            cin >> s[0] >> s[1];
            if (s[1] == "high") {
                high[N] = true;
            } else if ( s[1] == "on" ) {
                break;
            } else    low[N] = true;
            cin >> N;
        } while (true);
        for (int i = 1; i <= 10; i += 1) {
            if ( (i >= N && low[i]) || (i <= N && high[i]) ) {
                cout << "Stan is dishonest\n";
                goto HELL;
            }
        }
        cout << "Stan may be honest\n";
HELL:;
    }

    return 0;
}















