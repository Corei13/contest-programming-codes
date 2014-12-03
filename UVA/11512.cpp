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

template <class T, int n> struct StaticTrie {
    int maxrep, prefixes;
    StaticTrie <T, n> **children;
    int index, *tail;

    StaticTrie (): maxrep(0), prefixes(0), children(NULL) {}

    void Init (int *tail) {
        this->tail = tail;
        index = *tail;
        maxrep = 0, prefixes = 0;
        if (children) {
            delete[] children;
            children = NULL;
        }
    }

    int value (typename T::const_iterator it) {
        return *it == 'A' ? 0 : (*it == 'C' ? 1 : (*it == 'G' ? 2 : /**it == 'T' ?*/ 3));
    }

    void Insert (typename T::const_iterator it, typename T::const_iterator end, int val = 1) {
        prefixes += val;
        if (it != end) {
            int i = value(it);
            if (!children) {
                children = new StaticTrie <T, n> *[n] ();
            }
            if (!children[i]) {
                (*tail)++;
                children[i] = this + (*tail - index);
                children[i]->Init(tail);
            }
            children[i]->Insert(++it, end, val);
            if (prefixes >= 2) {
                maxrep = max (maxrep, 1 + children[i]->maxrep);
            }
        } else if (prefixes >= 2) {
            maxrep = max(maxrep, 1);
        }
    }

    void Insert (const T&& word, int val = 1) {
        Insert(word.begin(), word.end(), val);
    }

    void Print (int tab = 0) {
        cout << "maxrep: " << maxrep << ", Prefixes: " << prefixes << ", Childrens:" << endl;
        if (children) {
            for (int i = 0; i < n; ++i) if (children[i]) {
                    cout << setw(tab) << i["ACGT"] << " -> ";
                    children[i]->Print(tab + 4);
                }
        }
    }

    ~StaticTrie () {
        if (children) {
            delete[] children;
        }
    }
};

StaticTrie <string, 4> *root = new StaticTrie <string, 4> [1024 * 1024] ();

void Print (StaticTrie <string, 4> *T, string *s) {
    if (T->maxrep == 1) {
        cout << *s << ' ' << T->prefixes << endl;
    } else if (T->children) {
        for (int i = 0; i < 4; ++i) if (T->children[i] && T->children[i]->maxrep == T->maxrep - 1) {
                s->push_back(i["ACGT"]);
                Print (T->children[i], s);
                return;
            }
    } else while (true) {}
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        string s;
        root->Init(new int());
        cin >> s;
        for (string::const_iterator it = s.begin(); it != s.end(); it++) {
            root->Insert(it, s.end());
        }
        string m = "";
        if (root->maxrep >= 2) {
            Print (root, &m);
        } else {
            cout << "No repetitions found!" << endl;
        }
    }

    return 0;
}
