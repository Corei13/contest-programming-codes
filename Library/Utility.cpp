/*
    Implementation of binary arithmetic operators from uninary arithmetic operators

    Usage:
        using namespace arithmetic_ops;
        struct A {
            ...
            A& operator += (const B& rhs) { ... }
        };
        ...
        A lhs;
        B rhs;
        A sum = lhs + rhs;

*/

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

/*
    Implementation of Kahan's Summation algorithm for floating point numbers.
*/

double KahanSummation (vector <double>& v) {
    double sum = 0.0, c = 0.0;
    for (auto a : v) {
        double y = a - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}

/*
    Implementation of various utility functions
*/

// variadic print function
template <typename Head>
constexpr void print (Head&& head) {
    cout << head << endl;
}
template <typename Head, typename... Tail>
constexpr void print (Head&& head, Tail&& ... tail) {
    cout << head << ' ';
    print(tail...);
}

// printing vector-like containers
template<typename T, template<typename E, typename A = allocator<E>> class Container>
ostream & operator << (ostream& os, const Container <T>& container) {
    auto head = container.begin(), tail = container.end();
    while (head != tail) {
        os << *head;
        if (++head != tail) {
            os << " ";
        }
    }
    return os;
}

// clone of python-like range function
// usage:
struct Range {
    using value_type = int;
    using iterator = Range;
    value_type head, tail, diff;
    Range (int head, int tail, int diff = 1): head(head), diff(diff) {
        if ((head < tail && diff < 0) || (head > tail && diff > 0)) {
            this->tail = this->head;
        } else {
            int n = (abs(tail - head + diff) - 1) / abs(diff);
            this->tail = head + n * diff;
        }
    }
    Range (int n): Range(0, n, 1) {}
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
    const value_type& operator * () {
        return head;
    }
    friend bool operator == (const Range& lhs, const Range& rhs) {
        return lhs.head == rhs.tail;
    }
    friend bool operator != (const Range& lhs, const Range& rhs) {
        return !(lhs == rhs);
    }
};
