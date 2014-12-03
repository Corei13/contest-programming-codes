#include <stdio.h>
#include <math.h>



char s[10*1024*1024] = {0}, out[10*1024*1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, i, I, j, k, sign, b[128];
long long n, l, N;

void readn_signed()
{
	sign = 1;
	n = 0;
	while( s[++count] != '\n' && s[count] != ' ' && s[count] !='\0' )
	{
		switch( s[count] )
		{
			case '-' : sign = -1;continue;
			default: n *= 10; n += ( s[count] - '0' );
		}
	}
	hell:
	n *= sign;
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
	for (i = cnt; i >= 0; --i)
	{
		out[++wcount] = tmp[i];
	}
}
char fib[1001][32][32] = {0};

void genFib ()
{
	fib[0] = '1';
}	

void writefib ( int n )
{
	

int main (int argc, char *argv[])
{
	
	fread_unlocked(s, sizeof(char), 10*1024*1024, stdin);
	readn();
	do
	{
		readn()
		writefib( n );
	}while ( n >= 0 );

	fwrite_unlocked(out,1,wcount+1,stdout);
	
	return 0;
}
