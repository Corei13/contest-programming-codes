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
	
	int x[105][105], a[105][105];
	string S;
	int T;
	int M, N;
	
	cin >> T;
	
	for ( int t = 0; t < T; t++ )
	{
		cin >> S;
		N = S.size();
		M = N;
		
		for (int i = 0; i < N; i += 1)
		{
			a[0][i] = (S[i] == '0');
		}
		for (int j = 1; j < N; j += 1)
		{
			cin >> S;
			for (int i = 0; i < N; i += 1)
			{
				a[j][i] = (S[i] == '0');
			}
		}

		for (int i = 0; i < M; i += 1)
		{
			x[i+1][0] = 0;
			for (int j = 0; j < N; j += 1)
			{
				if (a[i][j])
				{
					x[i+1][j+1] = 0;
				}
				else	x[i+1][j+1] = x[i+1][j]+1;
				//cout << x[i+1][j+1] << ' ';
			}
			//cout << '\n';
		}
		
		x[0][0] = 0;
		int tmp, land = 0;
		for (int j = 0; j < N; j += 1)
		{
			for (int i = 0; i < M; i += 1)
			{
				tmp = 10000000;
				for (int l = i; l >= 0; l -= 1)
				{
					tmp = min ( tmp, x[1+l][j+1] );
					land = max ( land, tmp*(i+1-l) );
					//cout << i << ' ' << j << ' ' << l << ' ' << x[1+l][j+1] << '/' <<tmp*(i+1-l) << '\n';
				}
			}
		}
		if (t)	cout << '\n';
		cout << land << '\n';
	}
	
	return 0;
}















