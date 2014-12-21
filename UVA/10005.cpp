#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VS = vector<string>;
using PI = pair<int, int>;
using VPI = vector<PI>;
using VVPI = vector<VPI>;
using VD = vector<double>;
using VVD = vector<VD>;

template <typename Head>
constexpr void print (Head&& head) {
    cout << head << endl;
}
template <typename Head, typename... Tail>
constexpr void print (Head&& head, Tail&& ... tail) {
    cout << head << ' ';
    print(tail...);
}

namespace arithmetic_ops {
    template <class L, class R> L operator + (L lhs, const R& rhs) {
        lhs += rhs;
        return lhs;
    }

    template <class L, class R> L operator - (L lhs, const R& rhs) {
        lhs -= rhs;
        return lhs;
    }

    template <class L, class R> L operator * (L lhs, const R& rhs) {
        lhs *= rhs;
        return lhs;
    }

    template <class L, class R> L operator / (L lhs, const R& rhs) {
        lhs /= rhs;
        return lhs;
    }
};

#define EPS 1e-9

template <typename T> struct Point {
    T x, y;

    Point (T x = T(), T y = T()): x(x), y(y) {}

    Point (const Point& p): x(p.x), y(p.y) {}

    Point& operator += (const Point& p) {
        x += p.x, y += p.y;
        return *this;
    }

    friend inline Point operator + (Point lhs, const Point& rhs) {
        lhs += rhs;
        return lhs;
    }

    Point& operator -= (const Point& p) {
        x -= p.x, y -= p.y;
        return *this;
    }

    Point& operator += (const T& c) {
        x += c, y += c;
        return *this;
    }

    Point& operator -= (const T& c) {
        x -= c, y -= c;
        return *this;
    }

    Point& operator *= (const T& c) {
        x *= c, y *= c;
        return *this;
    }

    Point& operator /= (const T& c) {
        x /= c, y /= c;
        return *this;
    }

    bool operator == (const Point& p) const {
        return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS;
    }

    bool operator < (const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }

    friend ostream& operator << (ostream& os, Point <T>&& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend ostream& operator << (ostream& os, Point <T>& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend T norm (Point P) {
        return P.x * P.x + P.y * P.y;
    }

    friend Point unit (Point P) {
        return P / sqrt(norm(P));
    }

    friend Point RotateCCW90 (Point p) {
        return Point(-p.y, p.x);
    }

    friend Point RotateCW90 (Point p) {
        return Point(p.y, -p.x);
    }

    // Rotate clockwise by angle t
    friend Point RotateCCW (Point p, double t) {
        return Point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
    }

    friend T dot (Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    friend T cross (Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    friend T dist2 (Point a, Point b) {
        return dot(a - b, a - b);
    }

    // project point c on line (a, b)
    friend Point ProjectPointLine (Point a, Point b, Point c) {
        return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
    }

    // project point c onto line segment [a, b]
    friend Point ProjectPointSegment(Point a, Point b, Point c) {
        T r = dot(b - a, b - a);
        if (abs(r) <= EPS) {
            return a;
        }
        r = dot(c - a, b - a) / r;
        if (r < T(0)) return a;
        if (r > T(1)) return b;
        return a + (b - a) * r;
    }

    // compute distance from c to segment [a, b]
    friend T DistancePointSegment(Point a, Point b, Point c) {
        return sqrt(dist2(c, ProjectOnSegment(a, b, c)));
    }

    // determine if lines (a, b) and (c, d) are parallel or collinear
    friend bool LinesParallel(Point a, Point b, Point c, Point d) {
        return abs(cross(b - a, c - d)) <= EPS;
    }

    friend bool LinesCollinear(Point a, Point b, Point c, Point d) {
        return LinesParallel(a, b, c, d) && abs(cross(a - b, a - c)) <= EPS && abs(cross(c - d, c - a)) <= EPS;
    }

    // determine if line segment [a, b] intersects with line segment [c, d]
    friend bool SegmentsIntersect(Point a, Point b, Point c, Point d) {
        if (LinesCollinear(a, b, c, d)) {
            if (dist2(a, c) <= EPS || dist2(a, d) <= EPS || dist2(b, c) <= EPS || dist2(b, d) <= EPS) {
                return true;
            } else if (dot(c - a, c - b) > T(0) && dot(d - a, d - b) > T(0) && dot(c - b, d - b) > T(0)) {
                return false;
            } else {
                return true;
            }
        } else {
            return cross(d - a, b - a) * cross(c - a, b - a) <= T(0) && cross(a - c, d - c) * cross(b - c, d - c) <= T(0);
        }
    }

    // intersection point between lines (a, b) and (c, d)
    friend Point LineLineIntersection(Point a, Point b, Point c, Point d) {
        b = b - a, d = c - d, c = c - a;
        assert(dot(b, b) >= EPS && dot(d, d) >= EPS);
        return a + b * cross(c, d) / cross(b, d);
    }

    // compute center of circle given three points
    friend Point CircleCenter(Point a, Point b, Point c) {
        b = (a + b) / T(2);
        c = (a + c) / T(2);
        return LineLineIntersection(b, b + RotateCW90(a - b), c, c + RotateCW90(a - c));
    }

    // returns 1(0) if p is a strictly interior (exterior) point of v
    friend bool PointInPolygon(const vector<Point>& v, Point p) {
        bool ret = false;
        for (auto q = v.begin(); q != v.end(); q++) {
            auto r = (next(q) == v.end() ? v.begin() : next(q));
            if ((q->y <= p.y && p.y < r->y || r->y <= p.y && p.y < q->y) &&
                    p.x < q->x + (r->x - q->x) * (p.y - q->y) / (r->y - q->y)) {
                ret = !ret;
            }
        }
        return ret;
    }

    // determine if point is on the boundary of a polygon
    friend bool PointOnPolygon(const vector<Point>& v, Point p) {
        for (auto q = v.begin(); q != v.end(); q++) {
            auto r = (next(q) == v.end() ? v.begin() : next(q));
            if (dist2(ProjectPointSegment(*q, *r, p), p) <= EPS) {
                return true;
            }
        }
        return false;
    }

    // compute intersection of line (a, b) with circle centered at c with radius r > 0
    friend vector <Point> CircleLineIntersection(Point a, Point b, Point c, T r) {
        vector <Point> ret;
        b = b - a;
        a = a - c;
        T A = dot(b, b);
        T B = dot(a, b);
        T C = dot(a, a) - r * r;
        T D = B * B - A * C;
        if (D <= -EPS) {
            return ret;
        }
        ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
        if (D >= EPS)  {
            ret.push_back(c + a + b * (-B - sqrt(D)) / A);
        }
        return ret;
    }

    // compute intersection of circle centered at a with radius r with circle centered at b with radius R
    friend vector<Point> CircleCircleIntersection(Point a, Point b, T r, T R) {
        vector<Point> ret;
        T d = sqrt(dist2(a, b));
        if (d > r + R || d + min(r, R) < max(r, R)) {
            return ret;
        }
        T x = (d * d - R * R + r * r) / (d * T(2));
        T y = sqrt(r * r - x * x);
        Point v = (b - a) / d;
        ret.push_back(a + v * x + RotateCCW90(v) * y);
        if (y > T(0)) {
            ret.push_back(a + v * x - RotateCCW90(v) * y);
        }
        return ret;
    }

    friend T SignedArea(const vector<Point>& v) {
        T area(0);
        for (auto p = v.begin(); p != v.end(); p++) {
            auto q = (next(p) == v.end() ? v.begin() : next(p));
            area = area + (p->x * q->y - q->x * p->y);
        }
        return area / 2.0;
    }

    friend T Area(const vector<Point>& v) {
        return abs(SignedArea(v));
    }

    friend Point Centroid(const vector<Point>& v) {
        Point c(0, 0);
        T scale = 6.0 * SignedArea(v);
        for (auto p = v.begin(); p != v.end(); p++) {
            auto q = (next(p) == v.end() ? v.begin() : next(p));
            c = c + (*p + *q) * (p->x * q->y - q->x * p->y);
        }
        return c / scale;
    }

    // tests whether or not a given polygon (in CW or CCW order) is simple
    friend bool IsSimple(const vector<Point>& v) {
        for (auto p = v.begin(); p != v.end(); p++) {
            for (auto r = next(p); r != v.end(); r++) {
                auto q = (next(p) == v.end() ? v.begin() : next(p));
                auto s = (next(r) == v.end() ? v.begin() : next(r));
                if (p != s && q != r && SegmentsIntersect(*p, *q, *r, *s)) {
                    return false;
                }
            }
        }
        return true;
    }

    // area x 2 of triangle (a, b, c)
    friend T TwiceArea (Point a, Point b, Point c) {
        return cross(a, b) + cross (b, c) + cross (c, a);
    }

    friend T area2 (Point a, Point b, Point c) {
        return cross(a, b) + cross(b, c) + cross(c, a);
    }

    friend void ConvexHull(vector<Point>& v) {
        sort(v.begin(), v.end());
        vector<Point> up, dn;
        for (auto& p : v) {
            while (up.size() > 1 && area2(up[up.size() - 2], up.back(), p) >= 0) {
                up.pop_back();
            }
            while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), p) <= 0) {
                dn.pop_back();
            }
            up.push_back(p);
            dn.push_back(p);
        }
        v = dn;
        v.pop_back();
        reverse(dn.begin(), dn.end());
        for (auto& p : dn) {
            v.push_back(p);
        }
    }
};

using namespace arithmetic_ops;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    for (int n; cin >> n && n != 0;) {
        vector <Point <double>> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }
        double R;
        cin >> R;
        bool found = (n <= 1);
        for (int i = 0; i < n and !found; ++i) {
            for (int j = i + 1; j < n and !found; ++j) {
                if (4.0 * R * R >= norm(points[i] - points[j])) {
                    Point <double> mid = (points[i] + points[j]) / 2.0, dir = unit(RotateCW90(points[i] - points[j]));
                    Point <double> center[2] {
                        mid + dir * sqrt(R * R - norm(points[i] - points[j]) / 4.0),
                        mid - dir * sqrt(R * R - norm(points[i] - points[j]) / 4.0)
                    };
                    for (int k = 0; k < 2 and !found; ++k) {
                        found = true;
                        for (int l = 0; l < n and found; ++l) {
                            if (dist2(center[k], points[l]) >= R * R + EPS) {
                                found = false;
                            }
                        }
                    }
                }
            }
        }
        cout << (found ? "The polygon can be packed in the circle." : "There is no way of packing that polygon.") << endl;
    }

    return 0;
}
