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


struct comp
{
	comp(){}
	
	bool operator () ( const data &a, const data &b )
	{	
		return a.X < b.X;
	}
};

map<string,int> w;
string s, t;
int N, M;
data u;
double d;
int T, e;

int main (int argc, char const* argv[])
{
	int cnt = 1;
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i += 1)
	{
		cin >> s >> d;
		w[s] = int(d*10 + 1e-5);
	}
	
	for (int i = 0; i < M; i += 1)
	{
		T = 0;
		
		while ( cin >> t >> s )
		{
			T += w[t];
			
			if (s[0] != '+')
			{
				break;
			}
		}

		cin >> e;
		e *= 10;

		
		cout << "Guess #" << cnt++ << " was ";
		
		if ( !( ( s == "<" && T < e ) || ( s == ">" && T > e ) || ( s == "=" && T == e ) || ( s == "<=" && T <= e ) || ( s == ">=" && T >= e ) ) )
		{
			cout << "in";
		}
		
		cout << "correct.\n";
	}
	
	
	return 0;
}

