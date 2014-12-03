#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <set>
#include <map>
#include <deque>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <ll, ll> PI;
typedef vector <PI> VPI;
typedef vector <VPI> VVPI;

typedef vector <ll> VL;
typedef vector <VL> VVL;

typedef vector <long double> VD;
typedef vector <VD> VVD;

const ll maxd = 100500;

const long double EPS = 1e-6;

ll gcd (ll a, ll b) {
    return a == 0 ? b : gcd (b % a, a);
}

struct Fraction {
    ll a, b, sign;

    Fraction (ll a = 0, ll b = 1) {
        if ( b < 0 ) {
            a = -a, b = -b;
        }
        if (a == 0) {
            b = 1;
        } else {
            ll d = gcd (abs(a), abs(b));
            a /= d, b /= d;
        }
        this->a = abs(a), this->b = abs(b), this->sign = (a >= 0 ? 1 : -1);
    }

    const long double value () const {
        return (sign * a) / (long double)(b);
    }

    bool operator < (const Fraction& f) const {
        if (sign != f.sign) {
            return sign < f.sign;
        } else {
            ll i = a / b, fi = f.a / f.b;
            if (i == fi) {
                if (f.a % f.b == 0) {
                    return (sign == -1);
                } else if (a % b == 0) {
                    return (sign == 1);
                } else {
                    return Fraction(f.sign * f.b, f.a % f.b) < Fraction(sign * b, a % b);
                }
            } else {
                return sign == 1 ?  (i < fi) : (i > fi);
            }
        }
    }

    bool operator == (const Fraction& f) const {
        return a == f.a && b == f.b && sign == f.sign;
    }

    bool operator >= (const Fraction& f) const {
        return !(*this < f);
    }

    long double operator - (const Fraction& f) const {
        return this->value() - f.value();
    }

    long double operator * (const long double& f) const {
        return this->value() * f;
    }

    int comapare (const Fraction& f) const {
        return ( mp(sign * a, b) == mp(f.sign * f.a, f.b) ) ? 0 : ( value() < f.value() ? -1 : 1 );
    }

    friend ostream& operator << (ostream& os, const Fraction& f) {
        os << f.value();
        return os;
    }
};

struct Point {
    Fraction x, y;

    Point (Fraction x = Fraction(), Fraction y = Fraction()): x(x), y(y) {}

    bool operator < (const Point& P) const {
        return x.comapare(P.x) * 2 + y.comapare(P.y) < 0;
    }

    bool operator >= (const Point& P) const {
        return x == P.x ? (y >= P.y) : (x >= P.x);
    }

    friend ostream& operator << (ostream& os, const Point& P) {
        os << "[ " << P.x << ", " << P.y << " ]";
        return os;
    }
};

int cross (PI a, PI b, PI c) {
    ll cr = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return (cr == 0 ? 0 : (cr > 0 ? 1 : -1));
}

int cross (Point a, Point b, Point c) {
    long double cr = (a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y));

    return (cr < -EPS ? -1 : (cr > EPS ? 1 : 0));
}

struct Edge {
    Point a, b;

    Edge (Point a = Point(), Point b = Point()) : a(a), b(b) {}

    bool intersect (Edge e) {
        return (cross (a, e.a, b) * cross (a, e.b, b) <= 0) && (cross (e.a, a, e.b) * cross (e.a, b, e.b) <= 0);
    }

    bool contains (Point p) {
        return (cross (a, p, b) == 0 && ((a >= p && p >= b) || (b >= p && p >= a)));
    }

    bool contains (Edge e) {
        return contains(e.a) && contains(e.b);
    }

    bool operator < (const Edge& e) const {
        return mp(a, b) < mp(e.a, e.b);
    }

    bool operator != (const Edge& e) const {
        return (*this < e) || (e < *this);
    }

    Edge operator - () const {
        return Edge(b, a);
    }

    friend ostream& operator << (ostream& os, const Edge& e) {
        os << "( " << e.a << " -> " << e.b << " )";
        return os;
    }
};

Point __center, inf = Point (2 * maxd + 2, 2 * maxd + 3);

int e;
VPI p[2];
Point src, dst;
Edge srcEdge, dstEdge, periEdge;

bool atancomp (Point a, Point b) {
    return atan2 ( b.y.value() - __center.y.value(), b.x.value() - __center.x.value() ) < atan2 ( a.y.value() - __center.y.value(), a.x.value() - __center.x.value() );
}

int findCross () {
    set <Point> v;
    vector <Point> points;
    map <Edge, Edge> nxt;
    map <Point, vector <Point>> adj;
    map <Edge, int> label;

    for (int i = 0; i < e; ++i) {
        v.clear();
        for (int j = 0; j < e; ++j) if (i != j) {

                if (cross (p[0][i], p[0][j], p[1][i]) * cross (p[0][i], p[1][j], p[1][i]) > 0 || cross (p[0][j], p[0][i], p[1][j]) * cross (p[0][j], p[1][i], p[1][j]) > 0) {
                    continue;
                }

                ll D = ( p[0][i].y - p[1][i].y ) * ( p[0][j].x - p[1][j].x ) - ( p[0][j].y - p[1][j].y ) * ( p[0][i].x - p[1][i].x );
                if (D != 0) {
                    v.insert(Point(
                                 Fraction( ( p[0][i].x * p[1][i].y - p[0][i].y * p[1][i].x ) * ( p[0][j].x - p[1][j].x ) - ( p[0][j].x * p[1][j].y - p[0][j].y * p[1][j].x ) * ( p[0][i].x - p[1][i].x ), -D ),
                                 Fraction( ( p[0][i].x * p[1][i].y - p[0][i].y * p[1][i].x ) * ( p[0][j].y - p[1][j].y ) - ( p[0][j].x * p[1][j].y - p[0][j].y * p[1][j].x ) * ( p[0][i].y - p[1][i].y ), -D )
                             ));
                }

            }

        for (auto p : v) if (adj.find(p) == adj.end()) {
                adj[p] = vector <Point> ();
                points.push_back(p);
            }

        for (auto it = v.begin(); it != v.end();) {
            Point p = *it;
            it++;
            if (it != v.end()) {
                adj[p].push_back(*it);
                adj[*it].push_back(p);
            }
        }

    }
    for (auto p : points) {
        __center = p;
        sort(all(adj[p]), atancomp);

        if (!adj[p].empty()) {
            adj[p].pb(adj[p].front());
        }
        for (int i = 0; i < sz(adj[p]) - 1; ++i) {
            nxt[Edge(adj[p][i], p)] = Edge(p, adj[p][i + 1]);
        }
    }

    int regions = 0, srcRegion = -1, dstRegion = -1;
    for (auto it : nxt) if (label.find(it.x) == label.end()) {
            Edge ed = it.x;
            int srcIn = 0, dstIn = 0;
            do {
                label[ed] = regions;
                if (ed.intersect(Edge(src, Point(src.x.value() + 2 * maxd + 157, src.y.value() + 2 * maxd + 237)))) {
                    srcIn += 1;
                }
                if (ed.intersect(Edge(dst, Point(dst.x.value() + 2 * maxd + 157, dst.y.value() + 2 * maxd + 237)))) {
                    dstIn += 1;
                }
                ed = nxt[ed];
            } while (ed != it.x);
            if ((srcIn % 2 == 1) && (srcRegion == -1 || label[periEdge] != regions)) {
                srcRegion = regions;
            }
            if ((dstIn % 2 == 1) && (dstRegion == -1 || label[periEdge] != regions)) {
                dstRegion = regions;
            }
            regions++;
        }

    vector <map <int, int>> adjRegion(regions);
    for (auto it : label) {
        int u = label[-it.x];
        if (adjRegion[it.y].find(u) == adjRegion[it.y].end()) {
            adjRegion[it.y][u] = 1;
        }
        adjRegion[it.y][u] = min (adjRegion[it.y][u], int(!(srcEdge.contains(it.x) || dstEdge.contains(it.x))));
    }

    for (int i = 0; i < regions; ++i) {
        adjRegion[i][i] = 0;
    }

    deque <int> st;
    st.push_back(srcRegion);
    VI distance(regions, -1);
    distance[srcRegion] = 0;
    while (!st.empty()) {
        int u = st.front();
        st.pop_front();
        for (auto p : adjRegion[u]) {
            if (distance[p.x] == -1 || distance[u] + p.y < distance[p.x]) {
                distance[p.x] = distance[u] + p.y;
                if (p.y == 1) {
                    st.push_back(p.x);
                } else {
                    st.push_front(p.x);
                }
            }
        }
    }
    while (distance[dstRegion] == -1) {}
    return distance[dstRegion];
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    ll sx, sy, dx, dy;
    while (cin >> e >> sx >> sy >> dx >> dy) {
        src = Point(Fraction(sx), Fraction(sy));
        dst = Point(Fraction(dx), Fraction(dy));
        srcEdge = Edge(src, Point(Fraction(-2 * maxd), Fraction(-2 * maxd - 1)));
        dstEdge = Edge(dst, Point(Fraction(2 * maxd), Fraction(-2 * maxd - 1)));
        periEdge = Edge(Point(Fraction(-maxd), Fraction(-maxd)), Point(Fraction(-maxd), Fraction(maxd)));
        p[0].clear();
        p[1].clear();
        p[0].push_back(mp(sx, sy));
        p[1].push_back(mp(-2 * maxd, -2 * maxd - 1));
        p[0].push_back(mp(dx, dy));
        p[1].push_back(mp(2 * maxd, -2 * maxd - 1));

        p[0].push_back(mp(-maxd, -maxd));
        p[1].push_back(mp(-maxd,  maxd));

        p[0].push_back(mp(-maxd, maxd));
        p[1].push_back(mp( maxd, maxd));

        p[0].push_back(mp( maxd, maxd));
        p[1].push_back(mp( maxd, -maxd));

        p[0].push_back(mp( maxd, -maxd));
        p[1].push_back(mp(-maxd, -maxd));

        e += 6;
        //add extra containing all
        for (int i = 6; i < e; ++i) {
            cin >> sx >> sy >> dx >> dy;
            p[0].push_back(mp(sx, sy));
            p[1].push_back(mp(dx, dy));
        }
        cout << findCross() << '\n';
    }


    return 0;
}