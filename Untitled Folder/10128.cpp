#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>



#define X first
#define Y second


using namespace std;


int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	long long  dp[14][14][14];
	
	for (int s = 0; s < 14; s += 1)
	{
		for (int e = 0; e < 14; e += 1)
		{
			dp[1][s][e] = 0;
		}
	}
	dp[1][1][1] = 1;
	
	for (int n = 2; n < 14; n += 1)
	{
		for (int s = 0; s < 14; s += 1)
		{
			for (int e = 0; e < 14; e += 1)
			{
				dp[n][s][e] = 0;
				if ( s > 0 )	dp[n][s][e] += dp[n-1][s-1][e];
				if ( e > 0 )	dp[n][s][e] += dp[n-1][s][e-1];
				dp[n][s][e] += (n-2)*dp[n-1][s][e];
			}
		}
	}
	int T, N, S, E;
	cin >> T;
	for (int t = 0; t < T; t += 1)
	{
		cin >> N >> S >> E;
		if ( S <= N && E <= N)	cout << dp[N][S][E] << '\n';
		else			cout << "0\n";
	}
	return 0;
}















