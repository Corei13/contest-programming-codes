#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>


#define X first
#define Y second


using namespace std;

string print ( int n )
{
	string ret = "";
	int d[20];
	int m = n, i = 0;
	while (m > 0)
	{
		d[i++] = m%10;
		m /= 10;
	}
	i--;
	for (; i >= 0; i -= 1)
	{
		ret += char(d[i]+'0');
	}
	return ret;
}
int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	
	long long a[15];
	pair <long long,string> dp[15][15];
	int N, t = 0;
	
	while (cin >> N && N)
	{
		for (int i = 0; i < N; i += 1)
		{
			cin >> a[i] >> a[i+1];
		}
		
		for (int n = 0; n < N; n += 1)
		{
			dp[n][1] = make_pair(0,"A"+print(n+1));
		}
		
		for (int l = 2; l <= N; l += 1)
		{
			for (int n = 0; n+l <= N; n += 1)
			{
				dp[n][l].X = 1000000000000000000LL;
				for (int i = 1; i < l; i += 1)
				{
					if ( dp[n][i].X + dp[n+i][l-i].X + a[n]*a[n+i]*a[n+l] < dp[n][l].X )
					{
						dp[n][l] = make_pair( dp[n][i].X + dp[n+i][l-i].X + a[n]*a[n+i]*a[n+l], "(" + dp[n][i].Y + " x " + dp[n+i][l-i].Y + ")" );
					}
				}
			}
		}
		cout << "Case " << ++t << ": " << dp[0][N].Y << '\n';
	}
	
	return 0;
}















