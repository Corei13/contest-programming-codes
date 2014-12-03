#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <queue>
#include <deque>
#include <fstream>
#include <set>
#include <map>



#define MAXN 100005

#define pi pair <int, int>
#define Point pair <double, double>
#define data pair <string, double>
#define vi vector < int >
#define vvi vector < vi >
#define X first
#define Y second
#define all(v) (v).begin(), (v).end()
#define forall(i,n) for( int i = 0; i < n; ++i )
#define pb push_back
#define mp make_pair

using namespace std;

int adj[30][30];
int state[30];
int N, E, A, cnt;
char u[3];

int f ( char c )
{
	return int(c-'A');
}

int main (int argc, char const* argv[])
{
	while ( scanf ( "%d", &N ) != EOF )
	{
		scanf ( "%d %s", &E, u );
		
		for (int i = 0; i < 26; i += 1)
		{
			state[i] = 100;
			for (int j = 0; j < 26; j += 1)
			{
				adj[i][j] = 0;
			}
		}
		
		state[f(u[0])] = 0;
		state[f(u[1])] = 0;
		state[f(u[2])] = 0;
		
		
		for (int i = 0; i < E; i += 1)
		{
			scanf ( "%s", u );
			adj[f(u[0])][f(u[1])] = 1;
			adj[f(u[1])][f(u[0])] = 1;
		}
		
		for (int t = 0; t < 30; t += 1)
		{
			for (int i = 0; i < 26; i += 1)
			{
				if ( state[i] != 100 )	continue;;
				int tmp = 0;
				for (int j = 0; j < 26; j += 1)
				{
					if (adj[i][j] == 1 && state[j] <= t )
					{
						tmp++;
					}
				}
				if (tmp >= 3)
				{
					state[i] = t+1;
				//	cout << char(i+'A') << t+1 << '\n';
				}
			}
		}
		
		A = 0;
		cnt = 0;
		
		for (int i = 0; i < 26; i += 1)
		{
			if (state[i] != 100)
			{
				A = max ( A, state[i] );
				cnt++;
			}
		}
		
		if (cnt == N)
		{
			printf("WAKE UP IN, %d, YEARS\n", A);
		}
		else	printf("THIS BRAIN NEVER WAKES UP\n");
	}
	
	return 0;
}













