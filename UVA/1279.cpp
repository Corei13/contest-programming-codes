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
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

const double eps = 1e-9, epoch = 1e-6;

struct Vector {
    double x, y, z;

    Vector () {}
    
    Vector (double x, double y, double z): x(x), y(y), z(z) {}

    Vector operator + (const Vector &v) const {
        return Vector (x + v.x, y + v.y, z + v.z);
    }

    Vector operator - (const Vector &v) const {
        return Vector (x - v.x, y - v.y, z - v.z);
    }

    double operator * (const Vector &v) const {
        return (x * v.x + y * v.y + z * v.z);
    }

    Vector operator * (const double &r) const {
        return Vector (x * r, y * r, z * r);
    }

    double operator ^ (const Vector &v) const { // distance
        return (*this - v) * (*this - v);
    }
};

struct Asteroid {
    Vector r, v;
    double t;

    Asteroid (): t(0.0) {};

    Vector operator + (const double &t) const {
        return r + v * t;
    }
};

struct DisjointSet {
    int n;
    VI rank, parent;

    DisjointSet (int n): n(n), rank(n, 0) {
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

int n;
vector <Asteroid> a;
vector <pair <double, pair <PI, PI>>> collision;
vector <pair <double, PI>> edges;
int idx[64][64];
VVB taken;

bool MST (double t) {
    bool changed = false;
    DisjointSet* D = new DisjointSet(n);
    for (int i = 0; i < sz(edges); ++i) {
        edges[i].x = (a[edges[i].y.x] + t) ^ (a[edges[i].y.y] + t);
    }
    sort(all(edges));
    for (int i = 0; i < sz(edges); ++i) {
        idx[edges[i].y.x][edges[i].y.y] = i;
    }
    for (int i = 0; i < sz(edges); ++i) {
        if (D->Union(edges[i].y.x, edges[i].y.y)) {
            if (!taken[edges[i].y.x][edges[i].y.y]) {
                taken[edges[i].y.x][edges[i].y.y] = true;
                changed = true;
            }
        } else {
            if (taken[edges[i].y.x][edges[i].y.y]) {
                taken[edges[i].y.x][edges[i].y.y] = false;
                changed = true;
            }
        }
    }
    return changed;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int cs = 0;
    while (cin >> n) {
        a = vector <Asteroid> (n);
        collision.clear();
        edges.clear();

        for (int i = 0; i < n; ++i) {
            cin >> a[i].r.x >> a[i].r.y >> a[i].r.z >> a[i].v.x >> a[i].v.y >> a[i].v.z;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edges.push_back(make_pair(a[i].r ^ a[j].r, make_pair(i, j)));
                for (int k = i; k < n; ++k) {
                    for (int l = k + 1; l < n; ++l) if (k > i || l > j) {
                        double A = (a[i].v - a[j].v) * (a[i].v - a[j].v) - (a[k].v - a[l].v) * (a[k].v - a[l].v);
                        double B = (a[i].v - a[j].v) * (a[i].r - a[j].r) - (a[k].v - a[l].v) * (a[k].r - a[l].r);
                        double C = (a[i].r - a[j].r) * (a[i].r - a[j].r) - (a[k].r - a[l].r) * (a[k].r - a[l].r);
                        if (fabs(A) < eps) {
                            if (fabs(B) > eps) {
                                double t = - C / (B * 2.0);
                                if (t > 0.0) {
                                    collision.push_back(make_pair(t, make_pair(make_pair(i, j), make_pair(k, l))));
                                }
                            }
                        } else {
                            if (B * B >= A * C) {
                                double D = sqrt(B * B - A * C);
                                double t[2] = { (-B + D) / A, (-B - D) / A };
                                if (t[0] > 0.0) {
                                    collision.push_back(make_pair(t[0], make_pair(make_pair(i, j), make_pair(k, l))));
                                }
                                if (t[1] > 0.0) {
                                    collision.push_back(make_pair(t[1], make_pair(make_pair(i, j), make_pair(k, l))));
                                }
                            }
                        }
                    }
                }
            }
        }
        sort(all(collision));
        taken = VVB(n, VB(n, false));
        int answer = 0;
        bool operation = false;
        answer += MST(0.0);
        for (auto c = collision.begin(); c != collision.end();) {
            int i = c->y.x.x, j = c->y.x.y, k = c->y.y.x, l = c->y.y.y;
            double t = c->x + epoch;
            c++;

            int iij = idx[i][j], ikl = idx[k][l];
            double dij = (a[i] + t) ^ (a[j] + t), dkl = (a[k] + t) ^ (a[l] + t);
            if (iij < ikl && dij > dkl) {
                if (taken[i][j] && !taken[k][l]) {
                    operation = true;
                }
            } else if (iij > ikl && dij < dkl) {
                if (taken[k][l] && !taken[i][j]) {
                    operation = true;
                }
            }
            if ((c == collision.end() || c->x > t) && operation) {
                answer += MST(t);
                operation = false;
            }
        }
        cout << "Case " << ++cs << ": " << answer << endl;
    }

    return 0;
}