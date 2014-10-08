#include <bits/stdc++.h>

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
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

struct TopSort {
    int n;
    VVI adj;
    VI sorted;

    TopSort (int n): n(n), adj(n) {}

    void addEdge (int a, int b) {
        adj[a].push_back(b);
    }

    void dfs (int u, VB &marked) {
        if (marked[u]) {
            return;
        }
        for (auto v: adj[u]) {
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
    
    TopSort* T = new TopSort(26);
    VB flag(26, false);
    string s;
    VS word;
    while (cin >> s && s != "#") {
        for (int i = 0; i < sz(s); ++i) {
            flag[s[i]-'A'] = true;
        }
        word.push_back(s);
    }
    for (int i = 0; i < sz(word); ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < min(sz(word[i]), sz(word[j])); ++k) if (word[i][k] != word[j][k]) {
                T->addEdge(word[i][k] - 'A', word[j][k] - 'A');
                break;
            }
        }
    }
    T->sort();
    for (auto i: T->sorted) if (flag[i]) {
        cout << char(i+'A');
    }
    cout << endl;

    return 0;
}