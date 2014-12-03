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

int T, N, W[105], Tot;
bool dp[51][450*55];

int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	for (int i = 0; i < 55*405; i += 1)
	{
		dp[0][i] = false;
	}
	
	cin >> T;
	
	for (int t = 0; t < T; t += 1)
	{
		cin >> N;
		Tot = 0;
		for (int i = 0; i < N; i += 1)
		{
			cin >> W[i];
			Tot += W[i];
		}
		dp[0][0] = true;
		
		for (int j = 1; j <= (N+1)/2; j += 1)
		{
			for (int w = 0; w <= Tot/2; w += 1)
			{
				dp[j][w] = false;
			}
		}
		
		for (int i = 1; i <= N; i += 1)
		{
			for (int j = min(i,(N+1)/2); j >= 1; j -= 1)
			{
				for (int w = 0; w <= Tot/2; w += 1)
				{
					dp[j][w] = ( dp[j][w] || ( w >= W[i-1] && dp[j-1][w-W[i-1]] ) );
				}
			}
		}
		
		for (int w = Tot/2; w >= 0; w -= 1)
		{
			if (dp[N/2][w] || dp[(N+1)/2][w])
			{
				cout << w << ' ' << Tot - w << '\n';
				break;
			}
		}
	}
	
	return 0;
}










