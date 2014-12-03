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

struct G
{
	int T, P, S;
	G () {}
	bool operator < ( const G &g ) const
	{
		return T < g.T;
	}
};

int T, N, W[150], Tot;
long long dp[150][150], A, inf = 100000;

G g[150];

int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	g[0].T = 0;
	inf *= 10000000;
	
	
	dp[0][0] = 0;
	for (int k = 1; k < 150; k += 1)
	{
		dp[0][k] = -inf;
	}
	
	int Cases, N, K, Time;
	cin >> Cases;
	
	for (int c = 0; c < Cases; c += 1)
	{
		cin >> N >> K >> Time;
		
		for (int i = 1; i <= N; i += 1)
		{
			cin >> g[i].T;
		}
		
		for (int i = 1; i <= N; i += 1)
		{
			cin >> g[i].P;
		}
		
		for (int i = 1; i <= N; i += 1)
		{
			cin >> g[i].S;
		}
		
		sort ( g, g+N+1 );
		
		for (int i = 1; i <= N; i += 1)
		{
			for (int k = 0; k <= K; k += 1)
			{
				dp[i][k] = -inf;
				
				for (int a = 0; a <= K; a += 1)
				{
					if (abs(k-a) <= g[i].T - g[i-1].T)
					{
						dp[i][k] = max(dp[i][k], dp[i-1][a]);
					}
				}
				
				if (k == g[i].S && g[i].T <= Time)
				{
					dp[i][k] += g[i].P;
				}
			}
		}
		
		A = 0;
		if (c)
		{
			cout << '\n';
		}
		for (int i = 0; i <= K; i += 1)
		{
			A = max ( A, dp[N][i] );
		}
		
		cout << A << '\n';
	}

	return 0;
}










