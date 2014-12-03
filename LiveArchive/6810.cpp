#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        long long k;
        cin >> s >> k;
        int n = s.size();
        vector <int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(s[i] == 'W' ? 0 : (s[i] == 'R' ? 1 : 2));
        }
        for (int i = 0, j = 1; k != 0; i++, j = (j * 3) % n) {
            int d = k % 3LL;
            k /= 3LL;
            while (d != 0) {
                d--;
                for (int l = 0; l < n; ++l) {
                    a[l] += ((a[l] + a[(l + j) % n]) % 3) * 3;
                }
                for (int l = 0; l < n; ++l) {
                    a[l] /= 3;
                }
            }
        }
        int cnt[3] = {0, 0, 0};
        for (int i = 0; i < n; ++i) {
            cnt[a[i]]++;
        }
        cout << "Case #" << cs + 1 << ": " << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << endl;
    }

    return 0;
}