#include <stdio.h>



char s[10*1024*1024] = {0}, out[10*1024*1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, i, j, k, sign, b[128];
unsigned long long n, I, K;

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
	for (j = cnt; j >= 0; --j)
	{
		out[++wcount] = tmp[j];
	}
}


int main (int argc, char *argv[])
{

	fread_unlocked(s, sizeof(char), 10*1024*1024, stdin);
	
	readn();
	T = n;
	
	int T;
	long long dp[250], N, R;
	bool flag[250];
	vector < int > v;
	dp[1] = 0;
	flag[1] = true;
	int tmp;
	long long tmp2;
	for (int i = 2; i < 250; i += 1)
	{
		dp[i] = -1;
		flag[i] = 1;
	}
	
	for (int i = 2; i <= 243; i += 1)
	{
		if(dp[i] != -1)
		{
			continue;
			//cout << i << ' ' << dp[i] << '\n';
		}
		v.clear();
		tmp = i;
		do
		{
			flag[tmp] = false;
			v.push_back(tmp);
			//cout << tmp << " -- > " << f(tmp) << "\n";
			tmp  = f(tmp);
		} while ( dp[tmp] == -1 && flag[tmp] );
		
		if ( flag[tmp] )
		{
			tmp2 = dp[tmp];
		}
		else
		{
			tmp2 = -200000;
			tmp2 *= 200000;
		}
		
		while (!v.empty())
		{
			tmp = v.back();
			v.pop_back();
			dp[tmp] = ++tmp2;
			flag[tmp] = true;
		}
		//cout << i << ' ' << dp[i] << '\n';
	}
	cin >> T;
	
	for (int t = 0; t < T; t += 1)
	{
		cin >> N;
		R = 0;
		while (N > 243)
		{
			R++;
			N = f(N);
		}
		if( dp[N] < 0 )	cout << -1 << '\n';
		else		cout << R+dp[N] << '\n';
	}
	

	fwrite_unlocked(out,1,wcount+1,stdout);
	
	return 0;
}
