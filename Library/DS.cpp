/*
    Implementation of longest increasing subsequence algorithm

    Running time:
        O(n log(n))

    Usage:
        - Use LIS <T, std::less_equal>, LIS <T, std::greater_equal> to get longest increasing and longest decreasing
        subsequence, respectively
        - Use LIS <T, std::less>, LIS <T, std::greater> to get strictly longest increasing and strictly longest
        decreasing subsequence, respectively

    Input:
        - T, type of elements
        - F, function to compare, default is std::less
        - n, number of elements
        - a, vector of n elements

    Output:
        - lis, longest subsequence of a such that F(lis[i], lis[i + 1]) is true for each i
        - idx, idx[i] is the maximum integer such that there exists a subsequence b of a with b[idx[i]] = a[i]
        and F(b[j], b[j + 1]) is true for each j < idx[i]
*/

template <class T, class F = less_equal<T>> struct LongestIncreasingSubsequence {
    int n;
    vector <T> a;
    vector <int> lis, idx;

    struct {
        bool operator () (const pair <T, int>& a, const pair <T, int>& b) const {
            return F()(a.x, b.x);
        }
    } Compare;

    LongestIncreasingSubsequence (int n): n(n), a(n) {}

    int buildLIS () {
        vector <pair <T, int>> best;
        vector <int> prev(n, -1);
        idx = vector <int>(n, 0);

        for (int i = 0; i < n; i++) {
            auto u = make_pair(a[i], i);
            // cout << a[i] << endl;
            auto it = lower_bound(best.begin(), best.end(), u, Compare);

            if (it == best.end()) {
                if (best.empty()) {
                    prev[i] = -1, idx[i] = 0;
                } else {
                    prev[i] = best.back().y, idx[i] = idx[best.back().y] + 1;
                }
                best.push_back(u);
            } else {
                prev[i] = prev[it->y];
                idx[i] = idx[it->y];
                *it = u;
            }
        }

        lis.clear();
        for (int i = best.back().y; i >= 0; i = prev[i]) {
            lis.push_back(a[i]);
        }
        reverse(lis.begin(), lis.end());
        return int(lis.size());
    }
};

/*
    Implementation of disjoint-set data structure

    Running time:
        O(⍺(n)) per operation, where ⍺(n) is the inverse of Ackermann function

    Usage:
        - Find (x) returns the set containing x
        - Union (x, y) joins two sets containing x and y, returns false if x and y are in the same set

    Input:
        - n, number of sets
*/

struct DisjointSet {
    int n;
    vector <int> rank, parent;

    DisjointSet (int n): n(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int Find (int x) {
        return parent[x] == x ? x : (parent[x] = Find(parent[x]));
    }

    bool Union (int x, int y) {
        x = Find(x), y = Find(y);
        if (x == y) {
            return false;
        } else if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            rank[x] = max(rank[x], rank[y] + 1);
        }
        return true;
    }
};

/*
    Implementation of dynamic Prefix Tree (Trie) data structure

    Usage:
        - Initialize dynamicaly like: Trie <string, 26> *root = new Trie <string, 26> ()
        - Insert (word) inserts a iterable word (string, vector etc) into the Trie
        - Count (word) returns the total occurance of word and number of words having prefix word, respectively
        - If using pointer, don't forget to delete the Trie after each usage!
            Trie <string, 26> *root = new Trie <string, 26> ();
            ...
            delete root;

    Input:
        - T, an iterable class name like string, vector etc
        - n, alphabet size
        - value(), an function to convert item to alphabet index, like [a-z] to [0, 26) or [a-zA-Z] to [0, 52)

    Tested Problems:
        - Codeforces: 455B
        - UVA: 760, 12837
*/

template <class T, int n> struct Trie {
    int words, prefixes;
    Trie <T, n> **children;

    Trie (): words(0), prefixes(0), children (NULL) {}

    int value (typename T::const_iterator it) {
        // return *it; // for integers
        return *it - 'a'; // for lowercase strings
        // return *it - 'A'; // for uppercase strings
        // return 'a' <= *it && *it <= 'z' ? *it - 'a' : *it - 'A' + 26; // for both lower and uppercase strings
        // return *it - '0'; // for integer strings
    }

    void Insert (typename T::const_iterator it, typename T::const_iterator end, int val = 1) {
        prefixes += val;
        if (it != end) {
            int i = value(it);
            if (!children) {
                children = new Trie <T, n> *[n] ();
            }
            if (!children[i]) {
                children[i] = new Trie <T, n> ();
            }
            children[i]->Insert(++it, end, val);
        } else {
            words += val;
        }
    }

    void Insert (const T& word, int val = 1) {
        Insert(word.begin(), word.end(), val);
    }

    pair <int, int> Count (typename T::const_iterator it, typename T::const_iterator end) {
        if (it == end) {
            return make_pair (words, prefixes);
        } else {
            int i = value(it);
            return children[i] ? children[i]->Count(++it, end) : make_pair(0, 0);
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
            for (int i = 0; i < n; ++i) if (children[i]) {
                    delete children[i];
                }
            delete[] children;
        }
    }
};

/*
    Implementation of memory efficient static Prefix Tree (Trie) data structure

    Usage:
        - In this version, an array of StaticTrie pointers should be declared. Example:
            StaticTrie <string, 2> *root = new StaticTrie <string, 2> [2 * 1024 * 1024] ();
        - Initialize the Trie every time by calling Init() from root node: root->Init(new int())
        - Insert (word) inserts a iterable word (string, vector etc) into the Trie
        - Count (word) returns the total occurance of word and number of words having prefix word, respectively

    Input:
        - T, an iterable class name like string, vector etc
        - n, alphabet size
        - value(), an function to convert item to alphabet index, like [a-z] to [0, 26) or [a-zA-Z] to [0, 52)

    Tested Problems:
        - Live Archive: 4682
        - Codeforces: 455B
        - UVA: 760, 11512, 12837
*/

template <class T, int n> struct StaticTrie {
    int words, prefixes;
    StaticTrie <T, n> **children;
    int index, *tail;

    StaticTrie (): words(0), prefixes(0), children(NULL) {}

    void Init (int *tail) {
        this->tail = tail;
        index = *tail;
        words = 0, prefixes = 0;
        if (children) {
            delete[] children;
            children = NULL;
        }
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
                children = new StaticTrie <T, n> *[n] ();
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

    void Insert (const T&& word, int val = 1) {
        Insert(word.begin(), word.end(), val);
    }

    pair <int, int> Count (typename T::const_iterator it, typename T::const_iterator end) {
        if (it == end) {
            return make_pair (words, prefixes);
        } else {
            int i = value(it);
            return children && children[i] ? children[i]->Count(++it, end) : make_pair(0, 0);
        }
    }

    pair <int, int> Count (const T& word) {
        return Count(word.begin(), word.end());
    }

    void Print (int tab = 0) {
        cout << "Words: " << words << ", Prefixes: " << prefixes << ", Childrens:" << endl;
        if (children) {
            for (int i = 0; i < n; ++i) if (children[i]) {
                    cout << setw(tab) << i << " -> ";
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


template <class T, T I = T(0)> struct Matrix {
    int n, m;
    valarray <T> cells;

    Matrix (int n, int m): n(n), m(m), cells(I, n * m) {}

    Matrix (int n): Matrix (n, n) {}

    Matrix (vector <vector <T>>&& cells): n(cells.size()), m(cells[0].size()) {
        this->cells = valarray <T>(I, n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                this->cells[i * m + j] = cells[i][j];
            }
        }
    }

    inline T& operator() (unsigned int row, unsigned int col) {
        return cells[row * m + col];
    }

    inline T operator() (unsigned int row, unsigned int col) const {
        return cells[row * m + col];
    }

    inline Matrix operator - () const {
        return *this * -1;
    }

    inline Matrix& operator += (const Matrix& rhs) {
        cells += rhs.cells;
        return *this;
    }

    inline Matrix& operator -= (const Matrix& rhs) {
        cells -= rhs.cells;
        return *this;
    }

    inline Matrix& operator *= (const Matrix& rhs) {
        assert(m == rhs.n);
        valarray <T> product(I, n * rhs.m);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < m; ++k) {
                product[slice(i * rhs.m, rhs.m, 1)] += cells[i * m + k] * rhs.cells[slice(k * rhs.m, rhs.m, 1)];
            }
        }
        m = rhs.m;
        cells = product;
        return *this;
    }

    inline Matrix& operator += (const T& rhs) {
        cells += rhs;
        return *this;
    }

    inline Matrix& operator -= (const T& rhs) {
        cells -= rhs;
        return *this;
    }

    inline Matrix& operator *= (const T& rhs) {
        cells *= rhs;
        return *this;
    }

    inline Matrix& operator /= (const T& rhs) {
        cells /= rhs;
        return *this;
    }

    inline void eye () {
        assert(n == m);
        for (int i = 0; i < n; ++i) {
            cells[i * n + i] = 1;
        }
    }

    inline Matrix apply (function <int (T)> f) {
        Matrix a = *this;
        for (int i = 0; i < n * m; ++i) {
            a.cells[i] = f(cells[i]);
        }
        return a;
    }

    inline friend Matrix pow (const Matrix& base, long long n) {
        Matrix ret (base.n);
        ret.eye();
        int msb = -1;
        while (n >> (msb + 1)) {
            ++msb;
        }
        while (msb >= 0) {
            ret *= ret;
            if (n & (1LL << msb)) {
                ret *= base;
            }
            --msb;
        }
        return ret;
    }

    friend ostream& operator << (ostream& os, const Matrix& M) {
        for (int i = 0; i < M.n; ++i) {
            for (int j = 0; j < M.m; ++j) {
                os << setw (10) << M(i, j);
            }
            os << endl;
        }
        return os;
    }
};