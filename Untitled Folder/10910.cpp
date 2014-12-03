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
	
	long long binom[105][105];
	binom[0][0] = 1;
	
	for (int n = 1; n < 105; n += 1)
	{
		binom[n][0] = 1;
		binom[n][n] = 1;
		
		for (int r = 1; r <= n/2; r += 1)
		{
			binom[n][r] = binom[n-1][r] + binom[n-1][r-1];
			binom[n][n-r] = binom[n][r];
		}
	}
	
	int Test, T, P, N;
	cin >> Test;
	
	for (int t = 0; t < Test; t += 1)
	{
		cin >> N >> T >> P;
		if ( T - N*(P-1) >= N )	cout << binom[T - N*(P-1) - 1][N-1] << '\n';
		else			cout << 0 << '\n';
	}
	
	return 0;
}















