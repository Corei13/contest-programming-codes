#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-15

struct Fraction {
    
};

/*
    Common Geometry Routines
    Shamelessly copied from stanford acm notebook [http://web.stanford.edu/~liszt90/acm/notebook.html]
*/

template <class T> struct Point {
    T x, y;
    
    Point (T x, T y): x(x), y(y) {}
    
    Point (const Point &p): x(p.x), y(p.y) {}
    
    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    
    Point operator + (const T &c) const {
        return Point(x + c, y + c);
    }

    Point operator - (const T &c) const {
        return Point(x - c, y - c);
    }

    Point operator * (const T &c) const {
        return Point(x * c, y * c);
    }
    
    Point operator / (const T &c) const {
        return Point(x / c, y / c);
    }

    bool operator < (const Point &p) const {
        return make_pair (x, y) < make_pair (p.x, p.y);
    }

    friend ostream &operator << (ostream &os, Point <T> &&p) {
        os << "(" << p.x << ", " << p.y << ")";
    }

    friend ostream &operator << (ostream &os, Point <T> &p) {
        os << "(" << p.x << ", " << p.y << ")";
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
        if (abs(r) < EPS) {
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
        return abs(cross(b - a, c - d)) < EPS;
    }

    friend bool LinesCollinear(Point a, Point b, Point c, Point d) { 
        return LinesParallel(a, b, c, d) && abs(cross(a - b, a - c)) < EPS && abs(cross(c - d, c - a)) < EPS;
    }

    // determine if line segment [a, b] intersects with line segment [c, d]
    friend bool SegmentsIntersect(Point a, Point b, Point c, Point d) {
        if (LinesCollinear(a, b, c, d)) {
            if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) {
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
        assert(dot(b, b) > EPS && dot(d, d) > EPS);
        return a + b * cross(c, d) / cross(b, d);
    }

    // compute center of circle given three points
    friend Point CircleCenter(Point a, Point b, Point c) {
        b = (a + b) / T(2);
        c = (a + c) / T(2);
        return LineLineIntersection(b, b + RotateCW90(a - b), c, c + RotateCW90(a - c));
    }

    // returns 1(0) if p is a strictly interior (exterior) point of v
    friend bool PointInPolygon(const vector<Point> &v, Point p) {
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
    friend bool PointOnPolygon(const vector<Point> &v, Point p) {
        for (auto q = v.begin(); q != v.end(); q++) {
            auto r = (next(q) == v.end() ? v.begin() : next(q));
            if (dist2(ProjectPointSegment(*q, *r, p), p) < EPS) {
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
        if (D < -EPS) {
            return ret;
        }
        ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
        if (D > EPS)  {
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

    friend T SignedArea(const vector<Point> &v) {
        T area(0);
        for (auto p = v.begin(); p != v.end(); p++) {
            auto q = (next(p) == v.end() ? v.begin() : next(p));
            area = area + (p->x * q->y - q->x * p->y);
        }
        return area / 2.0;
    }

    friend T Area(const vector<Point> &v) {
        return abs(SignedArea(v));
    }

    friend Point Centroid(const vector<Point> &v) {
        Point c(0, 0);
        T scale = 6.0 * SignedArea(v);
        for (auto p = v.begin(); p != v.end(); p++) {
            auto q = (next(p) == v.end() ? v.begin() : next(p));
            c = c + (*p + *q) * (p->x * q->y - q->x * p->y);
        }
        return c / scale;
    }

    // tests whether or not a given polygon (in CW or CCW order) is simple
    friend bool IsSimple(const vector<Point> &v) {
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

    friend void ConvexHull(vector<Point> &v) {
        sort(v.begin(), v.end());
        vector<Point> up, dn;
        for (auto &p: v) {
            while (up.size() > 1 && area2(up[up.size()-2], up.back(), p) >= 0) {
                up.pop_back();
            }
            while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), p) <= 0) {
                dn.pop_back();
            }
            up.push_back(p);
            dn.push_back(p);
        }
        v = dn;
        v.pop_back();
        reverse(dn.begin(), dn.end());
        for (auto &p: dn) {
            v.push_back(p);
        }
    }
};





main(){
//   // expected: (-5,2)
  cerr << RotateCCW(Point<double>(2,5), M_PI/2) << endl;
  
//   // expected: (5,2)
  cerr << ProjectPointLine(Point<double>(-5,-2), Point<double>(10,4), Point<double>(3,7)) << endl;
  
  // expected: (5,2) (7.5,3) (2.5,1)
  cerr << ProjectPointSegment(Point<double>(-5,-2), Point<double>(10,4), Point<double>(3,7)) << " "
       << ProjectPointSegment(Point<double>(7.5,3), Point<double>(10,4), Point<double>(3,7)) << " "
       << ProjectPointSegment(Point<double>(-5,-2), Point<double>(2.5,1), Point<double>(3,7)) << endl;
  
  
  // expected: 1 0 1
  cerr << LinesParallel(Point<double>(1,1), Point<double>(3,5), Point<double>(2,1), Point<double>(4,5)) << " "
       << LinesParallel(Point<double>(1,1), Point<double>(3,5), Point<double>(2,0), Point<double>(4,5)) << " "
       << LinesParallel(Point<double>(1,1), Point<double>(3,5), Point<double>(5,9), Point<double>(7,13)) << endl;
  
  // expected: 0 0 1
  cerr << LinesCollinear(Point<double>(1,1), Point<double>(3,5), Point<double>(2,1), Point<double>(4,5)) << " "
       << LinesCollinear(Point<double>(1,1), Point<double>(3,5), Point<double>(2,0), Point<double>(4,5)) << " "
       << LinesCollinear(Point<double>(1,1), Point<double>(3,5), Point<double>(5,9), Point<double>(7,13)) << endl;
  
  // expected: 1 1 1 0
  cerr << SegmentsIntersect(Point<double>(0,0), Point<double>(2,4), Point<double>(3,1), Point<double>(-1,3)) << " "
       << SegmentsIntersect(Point<double>(0,0), Point<double>(2,4), Point<double>(4,3), Point<double>(0,5)) << " "
       << SegmentsIntersect(Point<double>(0,0), Point<double>(2,4), Point<double>(2,-1), Point<double>(-2,1)) << " "
       << SegmentsIntersect(Point<double>(0,0), Point<double>(2,4), Point<double>(5,5), Point<double>(1,7)) << endl;
  
  // expected: (1,2)
  cerr << LineLineIntersection(Point<double>(0,0), Point<double>(2,4), Point<double>(3,1), Point<double>(-1,3)) << endl;
  
  // expected: (1,1)
  cerr << CircleCenter(Point<double>(-3,4), Point<double>(6,1), Point<double>(4,5)) << endl;
  
  vector<Point<double>> v; 
  v.push_back(Point<double>(0,0));
  v.push_back(Point<double>(5,0));
  v.push_back(Point<double>(5,5));
  v.push_back(Point<double>(0,5));
  
  // expected: 1 1 1 0 0
  cerr << PointInPolygon(v, Point<double>(2,2)) << " "
       << PointInPolygon(v, Point<double>(2,0)) << " "
       << PointInPolygon(v, Point<double>(0,2)) << " "
       << PointInPolygon(v, Point<double>(5,2)) << " "
       << PointInPolygon(v, Point<double>(2,5)) << endl;
  
  // expected: 0 1 1 1 1
  cerr << PointOnPolygon(v, Point<double>(2,2)) << " "
       << PointOnPolygon(v, Point<double>(2,0)) << " "
       << PointOnPolygon(v, Point<double>(0,2)) << " "
       << PointOnPolygon(v, Point<double>(5,2)) << " "
       << PointOnPolygon(v, Point<double>(2,5)) << endl;
  
  // expected: (1,6)
  //           (5,4) (4,5)
  //           blank line
  //           (4,5) (5,4)
  //           blank line
  //           (4,5) (5,4)
  vector<Point<double>> u = CircleLineIntersection(Point<double>(0,6), Point<double>(2,6), Point<double>(1,1), 5);
  for (int i = 0; i < u.size(); i++) cerr << u[i] << " "; cerr << endl;
  u = CircleLineIntersection(Point<double>(0,9), Point<double>(9,0), Point<double>(1,1), 5);
  for (int i = 0; i < u.size(); i++) cerr << u[i] << " "; cerr << endl;
  u = CircleCircleIntersection(Point<double>(1,1), Point<double>(10,10), 5, 5);
  for (int i = 0; i < u.size(); i++) cerr << u[i] << " "; cerr << endl;
  u = CircleCircleIntersection(Point<double>(1,1), Point<double>(8,8), 5, 5);
  for (int i = 0; i < u.size(); i++) cerr << u[i] << " "; cerr << endl;
  u = CircleCircleIntersection(Point<double>(1,1), Point<double>(4.5,4.5), 10, sqrt(2.0)/2.0);
  for (int i = 0; i < u.size(); i++) cerr << u[i] << " "; cerr << endl;
  u = CircleCircleIntersection(Point<double>(1,1), Point<double>(4.5,4.5), 5, sqrt(2.0)/2.0);
  for (int i = 0; i < u.size(); i++) cerr << u[i] << " "; cerr << endl;
  
  // area should be 5.0
  // centroid should be (1.1666666, 1.166666)
  Point<double> pa[] = { Point<double>(0,0), Point<double>(5,0), Point<double>(1,1), Point<double>(0,5) };
  vector<Point<double>> p(pa, pa+4);
  Point<double> c = Centroid(p);
  cerr << "Area: " << Area(p) << endl;
  cerr << "Centroid: " << c << endl;
  
  return 0;
}