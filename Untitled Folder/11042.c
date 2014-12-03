#include <stdio.h>
#include <math.h>


char s[10*1024*1024] = {0}, out[10*1024*1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, i, I, j, k, sign, a, b, written, k;
long long n, l;
double N, theta, r;

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


int main (int argc, char *argv[])
{
	double C = 60*log(2);
	double PI = 2*acos(0);
	fread_unlocked(s, sizeof(char), 10*1024*1024, stdin);
	readn();
	int i, t = n;
	for (I = 0; I < t; I += 1)
	{
		readn_signed();
		a = n;
		readn_signed();
		b = n;
		theta = atan2 (b, a)/PI;
		r = log( (double)( a*a + b*b ) );
		written = 1;


		for (k = 1; k <= 4; k += 1)
		{

			if ( k*r <= C && fabs ( k*theta - (int)(k*theta + 0.5) ) < 0.00001 )
			{

				writen(k);
				written = 101;
				break;
			}
		}
		if ( written != 101 )
		{
			out[++wcount] = 'T';
			out[++wcount] = 'O';
			out[++wcount] = 'O';
			out[++wcount] = ' ';
			out[++wcount] = 'C';
			out[++wcount] = 'O';
			out[++wcount] = 'M';
			out[++wcount] = 'P';
			out[++wcount] = 'L';
			out[++wcount] = 'I';
			out[++wcount] = 'C';
			out[++wcount] = 'A';
			out[++wcount] = 'T';
			out[++wcount] = 'E';
			out[++wcount] = 'D';

		}

		out[++wcount] = '\n';
	}

	fwrite_unlocked(out,1,wcount+1,stdout);
	
	return 0;
}
