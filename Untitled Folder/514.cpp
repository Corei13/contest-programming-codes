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

int N, a, cnt;
deque <int> v, S;

int main (int argc, char const* argv[])
{
	while ( scanf("%d",&N) != EOF && N )
	{
		while ( scanf("%d",&a) != EOF && a )
		{
			S.clear();
			v.clear();
			S.pb(a);
			for (int i = 1; i < N; i += 1)
			{
				scanf("%d",&a);
				S.pb(a);
			}
			cnt = 0;
			for (int i = 1; i <= N; i += 1)
			{
				v.push_back(i);
				while ( !v.empty() && v.back() == S[cnt] )
				{
					v.pop_back();
					cnt++;
				}
			}
			if (v.empty())
			{
				printf("Yes\n");
			}
			else	printf("No\n");
		}
		printf("\n");
	}
	
	return 0;
}












