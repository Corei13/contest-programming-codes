#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits>
#include <string>
#include <algorithm>


#define X first
#define Y second


using namespace std;

const int MAXD = 505, DIG = 9, BASE = 1000000000;
const unsigned long long BOUND = numeric_limits <unsigned long long> :: max () - (unsigned long long) BASE * BASE;

struct bignum
{
    int D, digits [MAXD / DIG + 2];

    inline void trim ()
    {
        while (D > 1 && digits [D - 1] == 0)
            D--;
    }

    inline void init (long long x)
    {
        memset (digits, 0, sizeof (digits));
        D = 0;

        do
        {
            digits [D++] = x % BASE;
            x /= BASE;
        }
        while (x > 0);
    }

    inline bignum (int x = 0)
    {
        init (x);
    }

   
    inline char *str ()
    {
        trim ();
        char *buf = new char [DIG * D + 1];
        int pos = 0, d = digits [D - 1];

        do
        {
            buf [pos++] = d % 10 + '0';
            d /= 10;
        }
        while (d > 0);

        reverse (buf, buf + pos);

        for (int i = D - 2; i >= 0; i--, pos += DIG)
            for (int j = DIG - 1, t = digits [i]; j >= 0; j--)
            {
                buf [pos + j] = t % 10 + '0';
                t /= 10;
            }

        buf [pos] = '\0';
        return buf;
    }

    inline bignum operator + (const bignum &o) const
    {
        bignum sum = o;
        int carry = 0;

        for (sum.D = 0; sum.D < D || carry > 0; sum.D++)
        {
            sum.digits [sum.D] += (sum.D < D ? digits [sum.D] : 0) + carry;

            if (sum.digits [sum.D] >= BASE)
            {
                sum.digits [sum.D] -= BASE;
                carry = 1;
            }
            else
                carry = 0;
        }

        sum.D = max (sum.D, o.D);
        sum.trim ();
        return sum;
    }
};

int N;
bignum dp[1005][1005], A[1005];

int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	dp[0][0] = 1;
	for (int i = 1; i < 1005; i += 1)
	{
		dp[i][0] = bignum(0);
	}
	A[0] = bignum(1);
	
	for (int s = 1; s < 1005; s += 1)
	{
		A[s] = bignum(0);
		for (int l = 1; l <= 1005; l += 1)
		{
			dp[s][l] = dp[s-1][l-1]+dp[s-1][l-1];
			if(s >= 2)	dp[s][l] = dp[s][l] + dp[s-2][l-1];
			if(s >= 3)	dp[s][l] = dp[s][l] + dp[s-3][l-1];
			A[s] =  A[s] + dp[s][l];
		}
	}
	
	while (cin >> N)
	{
		cout << A[N].str() << '\n';
	}
	
	return 0;
}















