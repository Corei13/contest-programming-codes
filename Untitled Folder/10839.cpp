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



bignum dp[3][35][35][35], ndp[3][35][35][35], ans[34];

int main (int argc, char const* argv[])
{	
	dp[2][0][1][0] = bignum(1);
	dp[3][0][0][1] = bignum(1);
	
	for (int n = 2; n <= 100; n += 1)
	{
		for (int n1 = 0; n1 <= min(n,33); n1 += 1)
		{
			for (int n2 = 0; n2 <= min(n-n1,33); n2 += 1)
			{
				int n3 = n - n1 - n2;
				if (n3 > 33)
				{
					continue;
				}
				if ( n1 > 0 )	dp[1][n1][n2][n3] = dp[2][n1-1][n2][n3] + dp[3][n1-1][n2][n3];
				if ( n2 > 0 )	dp[2][n1][n2][n3] = dp[3][n1][n2-1][n3] + dp[1][n1][n2-1][n3];
				if ( n3 > 0 )	dp[3][n1][n2][n3] = dp[1][n1][n2][n3-1] + dp[2][n1][n2][n3-1];
			}
		}
	}
	ans[0] = bignum(1);
	for (int i = 1; i < 34; i += 1)
	{
		if ( i%2 == 1 )
		{
			ans[i] = dp[1][i][i][i]/2;
		}
		else
		{
			ans[i] = dp[1][i][i][i] + dp[1][i/2][i/2][i/2];
			ans[i] = ans[i]/2;
		}
	}
	
	int T, N, n;
	
	cin >> T;
	
	for (int t = 1; t <= T; t += 1)
	{
		cin >> N;
		n = N/3;
		cout << "Case " << t << ": " << ans[n].str() << '\n';
	}
	
	return 0;
}










