#include <stdio.h>
#include <math.h>


char s[10*1024*1024] = {0}, out[10*1024*1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, k, sign, b[128];
long long n, l;


void readn()
{
	n = 0;
	++count;
	while ( s[count] == '\n' || s[count] == ' ' )
	{
		++count;
	}
	--count;
	while( s[++count] != '\n' && s[count] != ' ' && s[count] !='\0' )
	{
		n *= 10;
		n += ( s[count] - '0' );
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
	for (k = cnt; k >= 0; --k)
	{
		out[++wcount] = tmp[k];
	}

}


int main (int argc, char *argv[])
{
	int i;
	unsigned int f[77];
	f[1] = 1;
	f[2] = 2;
	f[3] = 2;
	for (i = 4; i < 77; i += 1)
	{
		f[i] = f[i-3] + f[i-2];
	}
	fread_unlocked(s, sizeof(char), 10*1024, stdin);
	readn();
	do
	{
		writen(f[n]);
		out[++wcount] = '\n';
		readn();
	} while ( n > 0 );
	fwrite_unlocked(out,1,wcount+1,stdout);
	
	return 0;
}
