#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;


template <class T, int n> struct Trie {
    int words, prefixes;
    Trie <T, n> **children;
    int index, *tail;

    Trie (): words(0), prefixes(0), children(NULL) {}

    void Init (int *tail) {
        this->tail = tail;
        index = *tail;
        words = 0, prefixes = 0, children = NULL;
    }

    int value (typename T::const_iterator it) {
        // return *it; // for integers
        // return *it - 'a'; // for lowercase strings
        // return *it - 'A'; // for uppercase strings
        // return 'a' <= *it && *it <= 'z' ? *it - 'a' : *it - 'A' + 26; // for both lower and uppercase strings
        return *it - '0'; // for integer strings
    }

    void Insert (typename T::const_iterator it, typename T::const_iterator end, int val = 1) {
        prefixes += val;
        if (it != end) {
            int i = value(it);
            if (!children) {
                children = new Trie <T, n> *[n] ();
            }
            if (!children[i]) {
                (*tail)++;
                children[i] = this + (*tail - index);
                children[i]->Init(tail);
            }
            children[i]->Insert(++it, end, val);
        } else {
            words += val;
        }
    }

    void Insert (const T&& word) {
        Insert(word.begin(), word.end());
    }

    pair <int, int> Count (typename T::const_iterator it, typename T::const_iterator end) {
        if (it == end) {
            return make_pair (words, prefixes);
        } else {
            int i = index(it);
            return children && children[i] ? children[i]->Count(++it, end) : make_pair(0, 0);
        }
    }

    pair <int, int> Count (const T& word) {
        return Count(word.begin(), word.end());
    }

    void Print (int tab = 0) {
        cout << "Words: " << words << ", Prefixes: " << prefixes << ", Childrens:" << endl;
        for (int i = 0; i < n; ++i) if (children[i]) {
                cout << setw(tab) << i << " -> ";
                children[i]->Print(tab + 4);
            }
    }

    ~Trie () {
        if (children) {
            delete[] children;
        }
    }
};

long long getMax (Trie <string, 2> *T, long long a, int i = 31) {
    if (i == -1) {
        return 0;
    } else {
        int b = (a >> i) & 1LL;
        if (!T->children) {
            return 0;
        } else if (T->children[b ^ 1]) {
            return (1LL << i) | getMax (T->children[b ^ 1], a, i - 1);
        } else if (T->children[b]) {
            return getMax (T->children[b], a, i - 1);
        }
    }
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    Trie <string, 2> *root = new Trie <string, 2> [2 * 1024 * 1024] ();

    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        int n;
        cin >> n;
        long long s = 0, ans = 0;
        root->Init(new int());
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            root->Insert(bitset <32>(s).to_string());
            s ^= a;
            ans = max (ans, getMax (root, s));
        }
        cout << ans << endl;
        delete root->tail;
    }

    return 0;
}