#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>



using namespace std;

#define N 1000005
unsigned int prime[N / 64];
int pi[N+5], div[N+5], P[80000], pc;
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
double E[N];
void sieve()
{
	unsigned int i;
	unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;
	for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
	{
		unsigned int i2 = i + i;
		for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
	}
}

void gPi()
{
	pi[0] = 0;
	pi[1] = 0;
	pi[2] = 1;
	P[0] = 2;
	pc = 1;
	//E[2] = 1;
	for (int i = 3; i < N; i += 1)
	{
		pi[i] = pi[i-1];
		if (gP(i) && (i&1))
		{
			P[pc++] = i;
			////cout << pc << " --> " << P[pc-1] << '\n';
			++pi[i];
			//E[i] = pc;
		}
	}
}

void count()
{
	div[1] = 0;
	int up;
	
	for (int i = 0; i < pc; i += 1)
	{
		up = N/P[i];
		for (int j = 1; j <= up; j += 1)
		{
			++div[P[i]*j];
		}
	}
}

void final ()
{
	int up;
	for (int i = 1; i < N; i += 1)
	{
		E[i] += pi[i];
		E[i] /= div[i];
		up = N/i;
		for (int j = 0; j < pi[up]; j += 1)
		{
			//cout << i << ' ' << P[j] << ' ' << j << ' ' << i*P[j] << '\n';
			E[i*P[j]] += E[i];
		}
	}
}
	

int main (int argc, char const* argv[])
{
	//ios::sync_with_stdio(false);
	
	memset( prime, -1, sizeof( prime ) );
	memset( div, 0, sizeof( div ) );
	memset( E, 0, sizeof( E ) );
	sieve();
	gPi();
	count();
	final();
	E[1] = 0;
	
	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; i += 1)
	{
		cin >> n;
		printf("Case %d: %.10lf\n", i+1, E[n]);
	}
	
	
	return 0;
}















