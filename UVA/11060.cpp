#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<int, int> PI;

struct TopSort {
    int n;
    VVI adj;
    VI sorted;

    TopSort (int n): n(n), adj(n) {}

    void addEdge (int a, int b) {
        adj[a].push_back(b);
    }

    void sort () {
        VI in(n, 0);
        for (int i = 0; i < n; ++i) {
            for (auto j : adj[i]) {
                in[j]++;
            }
        }
        sorted.clear();
        set<int> s;

        for (int i = 0; i < n; ++i) if (in[i] == 0) {
                s.insert(i);
            }
        while (!s.empty()) {
            auto it = s.begin();
            sorted.push_back(*it);
            for (auto i : adj[*it]) {
                --in[i];
                if (in[i] == 0) {
                    s.insert(i);
                }
            }
            s.erase(it);
        }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, cs = 0;
    while (cin >> n) {
        TopSort T(n);
        map <string, int> f;
        VS s(n);

        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            f[s[i]] = i;
        }
        int m;
        vector<VB> w(n, VB(n, false));
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string a, b;
            cin >> a >> b;
            T.addEdge(f[a], f[b]);
        }
        T.sort();
        cout << "Case #" << ++cs << ": Dilbert should drink beverages in this order:";
        for (auto i : T.sorted) {
            cout << " " << s[i];
        }
        cout << "." << endl << endl;
    }

    return 0;
}