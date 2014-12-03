#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

#define MAXN 1005
#define X first
#define Y second


using namespace std;


const int inf = 20000000;

int N;
pair <int, int>dp_up[MAXN], dp_down[MAXN];

int DP( int S[], int n )
{
	int L = 0, M;
	
	for (int i = 0; i < n; i += 1)
	{
		dp_up[i] = make_pair(1,S[i]);
		dp_down[i] = make_pair(1,S[i]);
		
		for (int j = 0; j < i; j += 1)
		{
			
		}
	}
	
	for (int i = 0; i < n; i += 1)
	
	return L;
}

int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	int S[MAXN];
	
	while (cin >> N && N)
	{
		for (int i = 0; i < N; i += 1)
		{
			cin >> S[i];
		}
		cout << DP(S,N) << '\n';
	}
	
	return 0;
}



