#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>



using namespace std;

long long H[25000];
long long binom[17][17], fact[17];

void genBinom ()
{
	for (int i = 0; i < 17; i += 1)
	{
		for (int j = 0; j < 17; j += 1)
		{
			binom[i][j] = 0;
		}
	}
	for (int i = 0; i < 17; i += 1)
	{
		binom[i][0] = 1;
		binom[i][i] = 1;
	}
	
	for (int n = 2; n < 17; n += 1)
	{
		for (int r = 1; r <= n/2; r += 1)
		{
			binom[n][r] = binom[n-1][r-1] + binom[n-1][r];
			binom[n][n-r] = binom[n][r];
		}
	}
}

int hash ( int a[] )
{
	int b[8];
	for (int i = 0; i < 8; i += 1)
	{
		b[i] = a[i] + i;
	}
	int ret = 0;
	
	for (int i = 1; i <= 8; i += 1)
	{
		ret += binom[17-i][8-i]*b[i-1];
		
		for (int j = i; j < 8; j += 1)
		{
			if (b[j] > b[i-1])
			{
				b[j]--;
			}
		}
	}
	return ret;
}

void genF ()
{
	fact[0] = 1;
	for (int i = 1; i < 17; i += 1)
	{
		fact[i] = fact[i-1]*i;
	}
}

long long ipow ( int b, int p )
{
	if (p == 0)		return 1;
	else if ( b == 0 )	return 0;
	else if ( p == 1 )	return b;
	
	long long tmp = ipow(b, p>>1);
	if (p&1)	return tmp*tmp*b;
	else		return tmp*tmp;
}

void print ( int B[] )
{
	//cout << "added : ";
	for (int i = 0; i < 10; i += 1)
	{
		//cout << B[i] << ' ';
	}
	//cout << '\n';
}

long long makeH ( int c[] )
{
	long long ret = 0;
	int i[8];
	int B[10];
	int k = 0;
	long long tmp;
	for ( int j = 0; j < 10; j++ )	B[j] = 0;
	int S = 0;
	for (i[0] = 0; i[0] < 10; i[0] += 1)
	{
		B[i[0]]++;
		S += i[0];
		for (i[1] = i[0]; i[1] < 10; i[1] += 1)
		{
			B[i[1]]++;
			S += i[1];
			for (i[2] = i[1]; i[2] < 10; i[2] += 1)
			{
				B[i[2]]++;
				S += i[2];
				for (i[3] = i[2]; i[3] < 10; i[3] += 1)
				{
					S += i[3];
					B[i[3]]++;
					for (i[4] = i[3]; i[4] < 10; i[4] += 1)
					{
						S += i[4];
						B[i[4]]++;
						for (i[5] = i[4]; i[5] < 10; i[5] += 1)
						{
							S += i[5];
							B[i[5]]++;
							for (i[6] = i[5]; i[6] < 10; i[6] += 1)
							{
								S += i[6];
								B[i[6]]++;
								for (i[7] = i[6]; i[7] < 10; i[7] += 1)
								{
									B[i[7]]++;
									S += i[7];
									tmp = fact[8]*(S/10);
									////cout << 1 << ' ' << tmp << '\n';
									for (int j = 0; j < 10; j += 1)
									{
										////cout << B[j] << ' ' << fact[B[j]] << '\n';
										tmp /= fact[B[j]];
										tmp *= ipow(c[j], B[j]);
									}
									//H[k++] = tmp;
									////cout << 2 << ' ' << tmp << '\n';
									ret += tmp;
									
									B[i[7]]--;
									S -= i[7];
								}
								B[i[6]]--;
								S -= i[6];
							}
							B[i[5]]--;
							S -= i[5];
						}
						B[i[4]]--;
						S -= i[4];
					}
					B[i[3]]--;
					S -= i[3];
				}
				B[i[2]]--;
				S -= i[2];
			}
			B[i[1]]--;
			S -= i[1];
		}
		B[i[0]]--;
		S -= i[0];
	}
	return ret;
}

int main (int argc, char const* argv[])
{
	//ios::sync_with_stdio(false);
	
	genBinom();
	genF();
	//makeH();
	
	double eps = 1e-5;
	int N;
	int c[10];
	double tf;
	int td;
	
	while ( cin >> N && N)
	{
		for (int i = 0; i < 10; i += 1)
		{
			c[i] = 0;
		}
		for (int i = 0; i < N; i += 1)
		{
			cin >> tf;
			tf *= 10.0;
			c[int(tf+eps)%10]++;
		}
		cout << makeH(c) << '\n';
	}
	
	
	return 0;
}















