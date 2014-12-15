#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <limits>

using namespace std;

#define X first
#define Y second

using namespace std;


const int MAXD = 205, DIG = 9, BASE = 1000000000;
const unsigned long long BOUND = numeric_limits <unsigned long long> :: max () - (unsigned long long) BASE * BASE;

struct bignum {
    int D, digits [MAXD / DIG + 2];

    inline void trim () {
        while (D > 1 && digits [D - 1] == 0)
            D--;
    }

    inline void init (long long x) {
        memset (digits, 0, sizeof (digits));
        D = 0;

        do {
            digits [D++] = x % BASE;
            x /= BASE;
        } while (x > 0);
    }

    inline bignum (int x = 0) {
        init (x);
    }


    inline char *str () {
        trim ();
        char *buf = new char [DIG * D + 1];
        int pos = 0, d = digits [D - 1];

        do {
            buf [pos++] = d % 10 + '0';
            d /= 10;
        } while (d > 0);

        reverse (buf, buf + pos);

        for (int i = D - 2; i >= 0; i--, pos += DIG)
            for (int j = DIG - 1, t = digits [i]; j >= 0; j--) {
                buf [pos + j] = t % 10 + '0';
                t /= 10;
            }

        buf [pos] = '\0';
        return buf;
    }

    inline bignum operator + (const bignum& o) const {
        bignum sum = o;
        int carry = 0;

        for (sum.D = 0; sum.D < D || carry > 0; sum.D++) {
            sum.digits [sum.D] += (sum.D < D ? digits [sum.D] : 0) + carry;

            if (sum.digits [sum.D] >= BASE) {
                sum.digits [sum.D] -= BASE;
                carry = 1;
            } else
                carry = 0;
        }

        sum.D = max (sum.D, o.D);
        sum.trim ();
        return sum;
    }
};

int main (int argc, char const *argv[]) {
    bignum binom[201][201];
    binom[0][0] = bignum(1);
    binom[1][0] = bignum(1);
    binom[1][1] = bignum(1);

    for (int n = 2; n < 201; n += 1) {
        binom[n][0] = bignum(1);
        binom[n][n] = bignum(1);

        for (int r = 1; r <= n / 2; r += 1) {
            binom[n][r] = binom[n - 1][r - 1] + binom[n - 1][r];
            binom[n][n - r] = binom[n][r];
        }
    }

    int T, N, K, A, a;
    cin >> T;

    for (int t = 1; t <= T; t += 1) {
        cin >> N >> K;

        A = 0;
        for (int i = 0; i < K; i += 1) {
            cin >> a;
            A += a;
        }

        if ( N + 1 - A < K ) {
            cout << 0 << '\n';
        } else    cout << binom[N + 1 - A][K].str() << '\n';
    }

    return 0;
}










