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

string s, S[1005];
int N;
pair < int, string > dp[1005][1005];

int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	while (cin >> s)
	{
		N = s.size();
		
		for (int i = 0; i < N; i += 1)
		{
			S[i] = "";
			S[i] += s[i];
		}
		
		for (int i = 0; i < N; i += 1)
		{
			dp[i][0] = make_pair(0,"");
			dp[i][1] = make_pair(0,S[i]);
		}
		
		for (int l = 2; l <= N; l += 1)
		{
			for (int i = 0; i+l <= N; i += 1)
			{
				if (S[i] == S[i+l-1])
				{
					dp[i][l] = make_pair(dp[i+1][l-2].X, S[i]+dp[i+1][l-2].Y+S[i+l-1] );
				}
				else
				{
					if ( dp[i][l-1].X < dp[i+1][l-1].X )
					{
						dp[i][l] = make_pair( dp[i][l-1].X+1, S[i+l-1] + dp[i][l-1].Y + S[i+l-1] );
					}
					else	dp[i][l] = make_pair( dp[i+1][l-1].X+1, S[i] + dp[i+1][l-1].Y + S[i] );
				}
			}
		}
		cout << dp[0][N].X << ' ' << dp[0][N].Y << '\n';
	}
	
	return 0;
}










