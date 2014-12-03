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


#define MAXN 100005

#define pi pair <int, int>
#define Point pair <double, double>
#define vi vector < int >
#define vvi vector < vi >
#define X first
#define Y second
#define all(v) (v).begin(), (v).end()
#define forall(i,n) for( int i = 0; i < n; ++i )
#define pb push_back
#define mp make_pair

using namespace std;


multiset <long long> lo, hi;
multiset <long long> :: iterator i;
long long a, m, n;

int main (int argc, char const* argv[])
{
	while ( scanf("%lld",&a) != EOF )
	{
		n++;
		if ( int(hi.size()) && a < *hi.begin() )
		{
			lo.insert(a);
		}
		else	hi.insert(a);
		
		if ( int(lo.size()) > int(hi.size()) )
		{
			i = lo.end();
			i--;
			hi.insert(*i);
			lo.erase(i);
		}
		else if ( int(hi.size()) > int(lo.size()) + 1 )
		{
			lo.insert(*hi.begin());
			hi.erase(hi.begin());
		}
		if ( n&1 )
		{
			printf("%lld\n", *hi.begin());
		}
		else
		{
			i = lo.end();
			i--;
			printf("%lld\n", (*i+*hi.begin())/2);
		}
	}
	
	
	return 0;
}

