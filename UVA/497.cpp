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

int parse ( string str ) {
    int ret = 0, sign = 1;
    if (str[0] == '-') {
        sign = -1;
    } else    ret = str[0] - '0';
    for (int i = 1; i < str.size(); i += 1) {
        ret *= 10;
        ret += str[i] - '0';
    }
    return ret * sign;
}
void find_lis(vector<int>& a, vector<int>& b) {
    vector<int> p(a.size());
    int u, v;

    if (a.empty()) return;
    b.clear();
    b.push_back(0);

    for (size_t i = 1; i < a.size(); i++) {
        // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
        if (a[b.back()] < a[i]) {
            p[i] = b.back();
            b.push_back(i);
            continue;
        }

        // Binary search to find the smallest element referenced by b which is just bigger than a[i]
        // Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.
        for (u = 0, v = b.size() - 1; u < v;) {
            int c = (u + v) / 2;
            if (a[b[c]] < a[i]) u = c + 1; else v = c;
        }

        // Update b if new value is smaller then previously referenced value
        if (a[i] < a[b[u]]) {
            if (u > 0) p[i] = b[u - 1];
            b[u] = i;
        }
    }

    for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}
int main (int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int T;
    string str;
    getline(cin, str);
    T = parse(str);
    getline(cin, str);
    vector <int> a, lis;

    for (int t = 0; t < T; t += 1) {
        a.clear();
        //cout << "Case " << t << '\n';
        while ( getline(cin, str) && str.size() && str[str.size() - 1] != '\n' ) {
            a.push_back( parse(str) );
            //  cout << a.back() << '\n';
        }
        find_lis(a, lis);
        if (t) {
            cout << '\n';
        }
        cout << "Max hits: " << lis.size() << '\n';
        for (int i = 0; i < lis.size(); i += 1) {
            cout << a[lis[i]] << '\n';
        }
    }

    return 0;
}















