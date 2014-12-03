#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits>
#include <string>
#include <algorithm>
#include <set>



#define X first
#define Y second


using namespace std;


int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	int T = 0, L, S, MAXS;
	int dp[27][505][27];
	
	for (int i = 1; i < 27; i += 1)
	{
		dp[1][i][i] = 1;
	}
	
	while (cin >> L >> S && (L+S))
	{
		cout << "Case " << ++T << ": ";
		MAXS = 27*L - (L*(L+1)/2);
		if (L > 26 || S > MAXS)
		{
			cout << 0 << '\n';
			continue;
		}
		for (int l = 2; l <= L; l += 1)
		{
			for (int s = 0; s <= MAXS; s += 1)
			{
				for (int i = 1; i < 27; i += 1)
				{
					dp[l][s][i] = 0;
				}
			}
			
			for (int s = 0; s <= MAXS; s += 1)
			{
				for (int i = 1; i < 27; i += 1)
				{
					for (int j = 1; j < i; j += 1)
					{
						if(s >= i)	dp[l][s][i] += dp[l-1][s-i][j];
					}
				}
			}
		}
		long long Ans = 0;
		for (int i = 1; i < 27; i += 1)
		{
			Ans += dp[L][S][i];
		}
		cout << Ans << '\n';
	}
	
	return 0;
}















