#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include <sstream>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 100500
#define pi pair <int, int>
#define y first
#define x second

using namespace std;

int N, M, cs, k, x[64 * 64][64], t[64 * 64], a[64], b[64], h, cnt;
vector <int> s[64], S;
map<int, int> f;

int main() {
    while ( cin >> N ) {
        S.clear();
        for (int i = 0; i < N; i += 1) {
            cin >> M;
            s[i].clear();
            for (int j = 0; j < M; j += 1) {
                cin >> h;
                s[i].push_back(h);
                S.push_back(h);
            }
        }

        sort(S.begin(), S.end());

        f.clear();
        cnt = 0;
        for (int i = 0; i < S.size(); i += 1)
            if (f.find(S[i]) == f.end())
                f[S[i]] = cnt++;

        for (int i = 0; i < cnt; i += 1)
            for (int j = 0; j < N; j += 1)
                x[i][j] = 0, t[i] = 0;

        for (int i = 0; i < N; i += 1)
            for (int j = 0; j < s[i].size(); j += 1)
                x[f[s[i][j]]][i] = 1;

        for (int i = 0; i < cnt; i += 1)
            for (int j = 0; j < N; j += 1)
                t[i] += x[i][j];

        for (int i = 0; i < N; i += 1)
            a[i] = 0;
        k = 0;
        for (int i = 0; i < cnt; i += 1) {
            k += t[i];
            int flag = 0;
            for (int j = 0; j < N; j += 1)
                b[j] = 0;
            for (int j = 0; j < N; j += 1) {
                if (x[i][j] && a[j]) {
                    flag = 1;
                    for (int k = 0; k < N; k += 1)
                        if (k != j)  b[k] |= (1 & x[i][k]);
                    b[j] = (t[i] == 1);
                }
            }
            k -= flag;
            for (int j = 0; j < N; j += 1)
                a[j] = (flag) ? b[j] : x[i][j];
        }
        cout << "Case " << ++cs << ": " << 2 * k - N - 1 << '\n';
    }

    return 0;
}







