#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

template <class T, int n> struct Trie {
    int counter;
    Trie <T, n> **children;

    Trie (): counter(0), children(NULL) {}

    int value (typename T::const_iterator it) {
        return *it == '#' ? 26 : *it - 'a';
    }

    bool Extend (int i) {
        if (!children) {
            children = new Trie <T, n> *[n] ();
        }
        if (!children[i]) {
            children[i] = new Trie <T, n> ();
            return true;
        }
        return false;
    }

    void Insert (typename T::const_iterator it, typename T::const_iterator end) {
        if (it != end) {
            int i = value(it);
            Extend (i);
            children[i]->Insert(++it, end);
        }
    }

    void Insert (const T& word) {
        Insert(word.begin(), word.end());
    }

    int Count (typename T::const_iterator it, typename T::const_iterator end) {
        if (it == end) {
            return counter;
        } else {
            int i = value(it);
            return children && children[i] ? children[i]->Count(++it, end) : 0;
        }
    }

    int Count (const T& word) {
        return Count(word.begin(), word.end());
    }

    ~Trie () {
        if (children) {
            for (int i = 0; i < n; ++i) if (children[i]) {
                    delete children[i];
                }
            delete[] children;
        }
    }
};


const int K = 10;

int main() {
    ios::sync_with_stdio(false);

    Trie <string, 27> *rootA, *rootB;

    int t;
    cin >> t;

    for (int cs = 0; cs < t; ++cs) {
        rootA = new Trie <string, 27> ();
        rootB = new Trie <string, 27> ();

        string s;
        cin >> s;

        int query;
        cin >> query;

        VS queryString(query);

        for (int i = 0; i < query; ++i) {
            string head, tail;
            cin >> head >> tail;
            reverse(all(tail));
            queryString[i] = head + "#" + tail;
            rootB->Insert(queryString[i]);
        }

        int n = s.size();

        for (int i = 0; i < n; ++i) {
            auto node = rootA;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (node->Extend(idx)) {
                    auto tmp = rootB;
                    int x = min (j, i + K - 1);
                    for (int k = i, l = 0; k <= x; k++) {
                        if (tmp->children && tmp->children[s[k] - 'a']) {
                            tmp = tmp->children[s[k] - 'a'];

                            if (tmp->children[26]) {
                                auto nxt = tmp->children[26];
                                int y = max (i, j - K + 1);

                                for (l = j; l >= y; l--) {
                                    if (nxt->children && nxt->children[s[l] - 'a']) {
                                        nxt = nxt->children[s[l] - 'a'];
                                        nxt->counter++;
                                    } else {
                                        break;
                                    }
                                }
                            }
                        } else {
                            break;
                        }
                    }
                }
                node = node->children[idx];
            }
        }

        cout << "Case " << cs + 1 << ":" << endl;
        for (int i = 0; i < query; ++i) {
            cout << rootB->Count(queryString[i]) << endl;
        }

        delete rootA;
        delete rootB;
    }

    return 0;
}