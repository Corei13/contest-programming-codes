#include <iostream>

using namespace std;

#define ninf -10000000000000LL

long long d[105][105], S[105], M;
int a, N;

void dp ( int len = 0 )
{
	if (len == 0)
	{
		for (int i = 1; i <= N; i += 1)
		{
			d[i][i-1] = 0;
		}
	}
	else
	{
		for (int i = 1; i <= N-len+1; i += 1)
		{
			M = ninf;
			for (int k = i; k < i+len; k += 1)
			{
				M = max ( M, S[k] - d[k+1][i+len-1] );
			}
			M -= S[i-1];
			for (int k = i+len-1; k >= i; k -= 1)
			{
				M = max ( M, S[i+len-1] - S[k-1] - d[i][k-1] );
			}
			d[i][i+len-1] = M;
		}
	}
	if ( len == N )	return;
	dp ( ++len );
}

int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	while (cin >> N && N != 0)
	{
		S[0] = 0;
		for (int i = 1; i <= N; i += 1)
		{
			cin >> a;
			S[i] = S[i-1] + a;
		}

		dp();
		cout << d[1][N] << '\n';
	}
	
	return 0;
}
