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
	
	long long dp[505][505];
	int n, k;
	
	for (int a = 500; a >= 0; a -= 1)
	{
		dp[a][a] = 0;
		dp[a][a+1] = 2*a;
		if(a)	dp[a][a-1] = 0;
		for (int b = a+2; b < 501; b += 1)
		{
			dp[a][b] = (b-a+1)*a+dp[a+1][b];
			for (int c = a+1; c <= (a+b+2)/2; c += 1)
			{
				dp[a][b] = min ( dp[a][c-1]+dp[c+1][b]+(b-a+1)*c , dp[a][b]);
			}
		}
	}
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t += 1)
	{
		cin >> n >> k;
		cout << "Case " << t << ": " << dp[k+1][n+k] << '\n';
	}
	
	return 0;
}















