//#include <iostream>
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
#define forall(i,n) for( int (i) = 0; (i) < (n); ++(i) )
#define pb push_back
#define mp make_pair

using namespace std;

int T, N, M, F, x[50500], y[50500];

int main (int argc, char const* argv[])
{
	scanf("%d",&T);
	
	for (int t = 0; t < T; t += 1)
	{
		scanf("%d %d %d",&N, &M, &F);
		
		for (int i = 0; i < F; i += 1)
		{
			scanf("%d %d",&x[i], &y[i]);
		}
		sort(x, x+F);
		sort(y, y+F);
		printf("(Street: %d, Avenue: %d)\n", x[(F-1)/2], y[(F-1)/2]);

	}
	
	return 0;
}












