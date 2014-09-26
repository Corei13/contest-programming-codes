struct LIS {
    int n;
    VI a, lis;

    LIS (int n): n(n), a(n) {}

    void buildLIS (int ord, VI &idx) { // ord = -1 for LDS
        VPI best;
        VI prev(n, -1);
        idx = VI(n, 0);
        
        for (int i = 0; i < n; i++) {
            PI u = make_pair(a[i] * ord, i);
            auto it = upper_bound(all(best), u);

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
        reverse(all(lis));
    }
};

struct DisjointSet {
    int n;
    VI rank, parent;

    DisjointSet (int n): n(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int Find (int x) {
        return parent[x] == x ? x : (parent[x] = Find(parent[x]));
    }

    bool Union (int x, int y) { // returns false if already connected
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