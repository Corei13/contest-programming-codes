// C++11 Examples

VI v {12213, 2134214, 1231, 241, 2341, 21421};

// Lambda format [capture] (params) -> return_type {statement}. Type is function<return_type, (params)>
auto f = [v](int& i, int *j) -> int {return -i + *j;};
auto g = [v](function<int (int&, int *)> f) {
    for (auto i : v) cout << f(i, &i) << endl;
};

sort (all(v), [](int i, int j) {
    return i < j;
});

auto comp = [](int a, int b) {
    return a * a < b * b;
};

set<int, decltype(comp)>(comp);

set<int, function<bool (int, int)>>s([](int i, int j) {
    return i * i > j * j;
});

for_each(all(v), [](i) {
    cout << i << endl;
})

// Some STL Functions
// adjacent_find(all(v), f) finds two i, j s.t. f(i, j)
// for_each (all(v), f) is equiv. to for(auto i: v) f(i);
// {all_of, any_of, none_of}(all(v), f)

//transform example
VI a {1, 2, 3, 4, 5}, b {10, 20, 30, 40, 50}, c(5);
transform(all(a), b.begin(), c.begin(), [](int i, int j) {
    return (i * 9 % j);
}); // c[i] = (a[i] * 9) % b[i]
transform(all(a), b.begin(), [](int i) {
    return i * 7;
}); // b[i] = a[i] * 7
transform(all(a), a.begin(), [](int i) {
    return i * i;
}); // a[i] *= a[i]

// merge (all(a), all(b), c.begin(), f) merge sorted ranges by f()
// inplace_merge(a.begin(), a.begin()+100, a.end(), f)

// set_union, set_intersection, set_difference, set_symmetric_difference (all(a), all(b), comp)

// stoi(s, nullptr, b) converts string s to base


#include <numeric>

// accumulate(all(v), init, f) returns f(f(...f(f(init, v[0]), v[1])...), v[n-1])
// iota(all(v), init) -> v = {init, init+1, init+2 ...}
// adjacent_difference(all(v), res, f) --> res = {v[0], f(v[0], v[1]), f(v[1], v[2])...}
// inner_product(all(a), b.begin(), init, f, g) -> accumulate({g(a[0], b[0]), g(a[1], b[1])...}, init, f)
// partial_sum(all(v), res, f) --> res = {v[0], f(v[0], v[1]), f(f(v[0], v[1]), v[2])...}
// res must have size greater than or equal to v

// Bit Hacks
// Looping Over all subsets of a number
for (int i = n; i != 0; i = (i - 1) & n) {
    cout << i << endl;
}
// Looping Over all set bits of a number
for (int m = n, i = (m & (m - 1)) ^ m; m != 0; m &= (m - 1), i = (m & (m - 1)) ^ m) {
    cout << i << endl;
}

double KahanSummation (VD& v) {
    double sum = 0.0, c = 0.0;
    for (auto a : v) {
        double y = a - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}

// converting integer to binary string
bitset<64>(12345).to_string()
// converting binary string to integer
bitset<64>("10010").to_ullong()
bitset<64>("10010").to_ulong()
bitset<64> foo;
cin >> foo;
int n = foo.to_ulong();