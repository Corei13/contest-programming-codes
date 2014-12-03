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
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef pair<ll, ll> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

template <class T, int n> struct Trie {
    int words, prefixes, lcs;
    Trie <T, n> **children;

    Trie (): words(0), prefixes(0), lcs(0), children(NULL) {}

    int index (typename T::const_iterator it) {
        return *it == 'a' ? 0 : (*it == 'c' ? 1 : (*it == 'g' ? 2 : /**it == t ?*/ 3));
    }

    void Insert (typename T::const_iterator it, typename T::const_iterator end, int val = 1) {
        prefixes |= val;
        if (prefixes == 3) {
            lcs = max (lcs, 1);
        }
        if (it != end) {
            int i = index(it);
            if (!children) {
                children = new Trie <T, n> *[n] ();
            }
            if (!children[i]) {
                children[i] = new Trie <T, n> ();
            }
            children[i]->Insert(++it, end, val);
            if (prefixes == 3) {
                lcs = max (lcs, 1 + children[i]->lcs);
            }
        } else {
            words |= val;
        }
    }

    void Insert (const T& word, int val = 1) {
        Insert(word.begin(), word.end(), val);
    }

    pair <int, int> Count (typename T::const_iterator it, typename T::const_iterator end) {
        if (it == end) {
            return make_pair (words, prefixes);
        } else {
            int i = index(it);
            return children[i] ? children[i]->Count(++it, end) : make_pair(0, 0);
        }
    }

    pair <int, int> Count (const T& word) {
        return Count(word.begin(), word.end());
    }

    void Print (int tab = 0) {
        cout << "LCS: " << lcs << ", Prefixes: " << prefixes << ", Childrens:" << endl;
        if (children) {
            for (int i = 0; i < n; ++i) if (children[i]) {
                    cout << setw(tab) << i["acgt"] << " -> ";
                    children[i]->Print(tab + 4);
                }
        }
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

void PrintLCS (Trie <string, 4> *T, string *s) {
    if (T->lcs == 1) {
        cout << *s << endl;
    } else if (T->children) {
        for (int i = 0; i < 4; ++i) if (T->children[i] && T->children[i]->lcs == T->lcs - 1) {
                s->push_back("acgt"[i]);
                PrintLCS(T->children[i], s);
                s->pop_back();
            }
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    string s, t;
    Trie <string, 4> *root;
    bool first = true;
    while (cin >> s >> t) {
        root = new Trie<string, 4> ();
        for (string::const_iterator it = s.begin(); it != s.end(); it++) {
            root->Insert(it, s.end(), 1);
        }
        for (string::const_iterator it = t.begin(); it != t.end(); it++) {
            root->Insert(it, t.end(), 2);
        }
        if (first) {
            first = false;
        } else {
            cout << endl;
        }
        if (root->lcs == 1) {
            cout << "No common sequence." << endl;
        } else {
            string lcs;
            PrintLCS(root, &lcs);
        }
        delete root;
    }

    return 0;
}