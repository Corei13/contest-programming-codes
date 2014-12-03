#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <cstring>


#define MAXN 251*251
#define X first
#define Y second


using namespace std;


const int inf = 2000000000;

int N;
int I[MAXN];
 
int LIS( int S[], int n )
{

	I[0] = -inf;

	int LisLength = 0;
 
	for( int i = 0; i < n; i++ )
	{
		if (S[i] == 0)	continue;
		int low, high, mid;
		low = 0;
		high = LisLength;
 
		while( low <= high )
		{
			mid = ( low + high ) / 2;
			if( I[mid] < S[i] )
				low = mid + 1;
			else
				high = mid - 1;
		}
		
		I[low] = S[i];
		if( LisLength < low )
			LisLength = low;
	}
 
	return LisLength;
}


int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	int W, P, Q, x, V[MAXN], S[MAXN];
	int T;
	
	cin >> T;
	
	for (int t = 1; t <= T; t += 1)
	{
		cin >> N >> P >> Q;
		memset ( V, 0, sizeof(V) );
		for (int i = 0; i <= P; i += 1)
		{
			cin >> x;
			V[x] = i+1;
		}
		for (int i = 0; i <= Q; i += 1)
		{
			cin >> x;
			S[i] = V[x];
		}
		cout << "Case " << t << ": " << LIS(S,Q+1) << '\n';
	}
	
	return 0;
}



