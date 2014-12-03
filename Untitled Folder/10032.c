#include <stdio.h>



char s[10*1024*1024] = {0}, out[10*1024*1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, i, j, k, sign, b[128];
unsigned long long n, I, K;

void readn()
{
	n = 0;
	while ( !( s[++count] <= '9' && s[count] >= '0' ) )
	{
		
	}
	--count;
	while( s[++count] <= '9' && s[count] >= '0' )
	{
		n *= 10; n += ( s[count] - '0' );
	}

}

void writen ( long long m )
{
	cnt = -1;
	char tmp[128] = {0};
	do
	{
		tmp[++cnt] = (char)( m%10 + 48 );
		m /= 10;
	}while ( m != 0 );
	for (j = cnt; j >= 0; --j)
	{
		out[++wcount] = tmp[j];
	}
}

int min ( int a , int b )
{
	if (a<b)
	{
		return a;
	}
	return b;
}

int T, N, W[105], Tot;
int dp[51][450*55], i, j, t, w;

int main (int argc, char *argv[])
{

	fread_unlocked(s, sizeof(char), 10*1024*1024, stdin);
	
	for (i = 0; i < 55*405; i += 1)
	{
		dp[0][i] = 0;
	}
	
	readn();
	T = n;
	
	for (t = 0; t < T; t += 1)
	{
		readn();
		N = n;
		Tot = 0;
		for (i = 0; i < N; i += 1)
		{
			readn();
			W[i] = n;
			Tot += W[i];
		}
		dp[0][0] = 1;
		
		for (j = 1; j <= (N+1)/2; j += 1)
		{
			for (w = 0; w <= Tot/2; w += 1)
			{
				dp[j][w] = 0;
			}
		}
		
		for (i = 1; i <= N; i += 1)
		{
			for (j = min(i,(N+1)/2); j >= 1; j -= 1)
			{
				for (w = 0; w <= Tot/2; w += 1)
				{
					dp[j][w] = ( dp[j][w] || ( w >= W[i-1] && dp[j-1][w-W[i-1]] ) );
				}
			}
		}
		if(t)	out[++wcount] = '\n';
		for (w = Tot/2; w >= 0; w -= 1)
		{
			if (dp[N/2][w] || dp[(N+1)/2][w])
			{
				writen(w);
				out[++wcount] = ' ';
				writen(Tot - w);
				out[++wcount] = '\n';
				break;
			}
		}
	}

	fwrite_unlocked(out,1,wcount+1,stdout);
	
	return 0;
}
