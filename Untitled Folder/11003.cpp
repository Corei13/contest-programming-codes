#include <iostream>

using namespace std;

struct Box {
    int W, cap;
    Box () {}
};

int N, Max, cap[1001];
Box B[1001];

void dp ( int n = 0 ) {
    if ( n == N )   return;
    if ( B[n].W <= cap[Max] ) {
        cap[Max + 1] = min(cap[Max] - B[n].W, B[n].cap);
        Max++;
    }
    for (int i = Max - 1; i >= 0; i -= 1) {
        if ( min(cap[i] - B[n].W, B[n].cap) > cap[i + 1] ) {
            cap[i + 1] = min(cap[i] - B[n].W, B[n].cap);
        }
    }
    dp(++n);
}

int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    while (cin >> N && N != 0) {
        for (int i = 0; i < N; i += 1) {
            cin >> B[i].W >> B[i].cap;
        }
        cap[0] = 1000000000;
        Max = 0;
        dp();
        cout << Max << '\n';
    }

    return 0;
}
