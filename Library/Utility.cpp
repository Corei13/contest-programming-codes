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
        lhs += rhs;
        return lhs;
    }

    template <class L, class R> L operator * (L lhs, const R& rhs) {
        lhs += rhs;
        return lhs;
    }

    template <class L, class R> L operator / (L lhs, const R& rhs) {
        lhs += rhs;
        return lhs;
    }
};