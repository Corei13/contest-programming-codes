namespace arithmetic_ops {
    template <class T, class E> T operator + (T lhs, const E& rhs) {
        lhs += rhs;
        return lhs;
    }

    template <class T, class E> T operator - (T lhs, const E& rhs) {
        lhs += rhs;
        return lhs;
    }

    template <class T, class E> T operator * (T lhs, const E& rhs) {
        lhs += rhs;
        return lhs;
    }

    template <class T, class E> T operator / (T lhs, const E& rhs) {
        lhs += rhs;
        return lhs;
    }
};