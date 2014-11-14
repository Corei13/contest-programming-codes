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
        bool operator () (const pair <T, int> &a, const pair <T, int> &b) const {
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