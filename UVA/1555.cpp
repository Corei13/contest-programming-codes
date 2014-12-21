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

template <class T> constexpr T identity (T& i) {
    return i;
};

template <typename F = function <int (int&)>> struct Range {
    using value_type = typename F::result_type;
    using iterator = Range;
    value_type head, tail, diff;
    F func;
    Range (int head, int tail, int diff = 1, F func = identity <value_type>): head(head), diff(diff), tail(head), func(func) {
        if ((head < tail && diff > 0) || (head > tail && diff < 0)) {
            int n = (abs(tail - head + diff) - 1) / abs(diff);
            this->tail = head + n * diff;
        }
    }
    Range (int n, F func = identity <value_type>): Range(0, n, 1, func) {}
    Range& operator = (const Range& that) {
        head = that.head, tail = that.tail, diff = that.diff, func = that.func;
    }
    iterator& begin() {
        return *this;
    }
    iterator& end() {
        return *this;
    }
    iterator& operator ++ () {
        head += diff;
        return *this;
    }
    const value_type operator * () {
        return func(head);
    }
    friend bool operator == (const Range& lhs, const Range& rhs) {
        return lhs.head == rhs.tail;
    }
    friend bool operator != (const Range& lhs, const Range& rhs) {
        return !(lhs == rhs);
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    for (int n; cin >> n;) {
        double a;
        cin >> a;
        auto f = [&a] (int i) -> double {
            return (-a - i * i) / double(i);
        };
        auto r = Range<>(1, n);
        double b = f(*max_element(all(r), [&f] (int lhs, int rhs) {
            return f(lhs) < f(rhs);
        }));
        cout << fixed << setprecision(2) << (n - 1) * (n - 1) + b * (n - 1) + a << endl;
    }

    return 0;
}
