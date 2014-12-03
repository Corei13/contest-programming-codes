#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

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
typedef pair<ll, ll> PI;

struct TopSort {
    int n;
    VVI adj;
    VI sorted;

    TopSort (int n): n(n), adj(n) {}

    void addEdge (int a, int b) {
        adj[a].push_back(b);
    }

    void dfs (int u, VB& marked) {
        if (marked[u]) {
            return;
        }
        for (auto v : adj[u]) {
            dfs(v, marked);
        }
        marked[u] = true;
        sorted.push_back(u);
    }

    void sort () {
        VB marked(n, false);
        sorted.clear();

        for (int i = 0; i < n; ++i) {
            dfs(i, marked);
        }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m && n >= 1) {
        TopSort T(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            T.addEdge(b - 1, a - 1);
        }
        T.sort();
        for (auto i : T.sorted) {
            cout << (i == T.sorted.front() ? "" : " ") << i + 1;
        }
        cout << endl;
    }

    return 0;
}