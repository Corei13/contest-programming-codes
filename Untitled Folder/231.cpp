#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

#define MAXN 100005
#define X first
#define Y second


using namespace std;


const int inf = 2000000000;

int N;
int I[MAXN];
 
void LIS( int s, int t )
{
	//ios::sync_with_stdio(false);
	I[0] = -inf;

	int LisLength = 0;
 	int S = -s;
	for( int i = 0; S != 1 ; i++ )
	{
		int low, high, mid;
		low = 0;
		high = LisLength;
 
		while( low <= high )
		{
			mid = ( low + high ) / 2;
			if( I[mid] <= S )
				low = mid + 1;
			else
				high = mid - 1;
		}
		
		I[low] = S;
		if( LisLength < low )
			LisLength = low;
			
		cin >> S;
		S *= -1;
	}
	if ( t > 1 )	cout << '\n';
	cout << "Test #" << t << ":\n  maximum possible interceptions: " << LisLength << '\n';
}


int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	int W, s, t = 0;
	
	while (cin >> s && s != -1)
	{
		LIS(s,++t);
	}
	
	return 0;
}

