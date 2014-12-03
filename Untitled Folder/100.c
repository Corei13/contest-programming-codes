#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char s[10*1024*1024] = {0}, out[10*1024*1024] = {0}, tmp[1024]={0};
static int count = -1, wcount = -1;
int cnt = -1, i, ii, t, I, j, J, k, K, sign, a[8192], Ans;
long long n, x[1000505];


int cycle ( long long N )
{
	int KK = 0;
	if (x[N] != -1)
	{
		return x[N];
	}
	do
	{

		if ( N&1 )	N = 3*N + 1;
		else		N >>= 1;

		KK++;
	}while (N > 1000500);
	return KK + cycle(N);
}

void readn()
{
	n = 0;
	while( s[++count] != '\n' && s[count] != ' ' && s[count] !='\0' )
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
	for (ii = cnt; ii >= 0; --ii)
	{
		out[++wcount] = tmp[ii];
	}
}


int max(int a, int b) {
    b = a-b;
    a -= b & (b>>31);
    return a;
}


int main (int argc, char *argv[])
{
	memset ( x, -1, sizeof(x));
	fread_unlocked(s, sizeof(char), 10*1024*1024, stdin);
	x[0] = 0;
	x[1] = 1;
	int Max, M[1005];/* M[i]:maximum between 1024i -> 1024(i+1)-1 */
	memset (M, 0, sizeof(M));
	
	for (i = 0; i < 977; i += 1)
	{
		M[i] = 0;
		for (I = 0; I < 1024; I += 1)
		{
			x[i*1024 + I] = cycle(i*1024+I);
			M[i] = max(M[i], x[i*1024 + I]);
		}
	}
	int iii, jjj;
	readn();
	do
	{
		iii = n;
		readn();
		jjj = n;
		
		j = max(iii,jjj);
		i = iii+jjj - j;
		
		Ans = 0;
		
		if ( (j-i) <= 1024 )
		{
			for (k = i; k <= j; k += 1)
			{
				Ans = max (Ans, x[k]);
			}
		}
		
		else
		{
			I = i&1023;
			if ( I )	J = ( ( i >> 10 ) + 1 ) << 10;
			else		J = i;
		
			K = (j+1)>>10;
			for (k = i; k < J; k += 1)
			{
				Ans = max ( Ans, x[k] );
			}
			for (k = (J>>10); k < K; k += 1)
			{
				
				Ans = max ( Ans, M[k] );
			
			}
			for (k = ( K<<10 ); k <= j; k += 1)
			{
				Ans = max ( Ans, x[k] );
			}
			
		}
		
		writen(iii);
		out[++wcount] = ' ';
		writen(jjj);
		out[++wcount] = ' ';
		writen(Ans);
		out[++wcount] = '\n';
		readn();
		
		
	} while (n >= 1);

	fwrite_unlocked(out,1,wcount+1,stdout);
	
	return 0;
}
