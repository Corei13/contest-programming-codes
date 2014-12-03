#include <iostream>
#include <deque>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

#define pi pair <int, int>
#define x first
#define y second
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define all(v) (v).begin(), (v).end()

using namespace std;

int N, ts;
vector <int> s, t;

long long find ( int n, vector <int> v, int x ) // x =0/1/2
{
	if(n == 0)
		return 0;
	if (v.back() == x)
	{
		v.pop_back();
		return find(n-1,v,x);
	}
	else
	{
		int y = 0;
		while( y == x || y == v.back())
			y++;
		v.pop_back();
		
		return ((1LL<<(n-1))+find(n-1,v,y));
	}
}

long long find ( int n, vector<int> a, vector<int> b )
{
	if(n == 0)
		return 0;
	if (a.back() == b.back())
	{
		a.pop_back();
		b.pop_back();
		return find(n-1,a,b);
	}
	
	int y = 0;
	while (y == a.back() || y == b.back())
		y++;
	a.pop_back();
	b.pop_back();
	return 1LL + find(n-1,a,y) + find(n-1,b,y);
}
		
int main (int argc, char const* argv[])
{
	while( cin >> N && N )
	{
		s = vector<int>(N);
		t = vector<int>(N);
		
		for (int i = 0; i < N; i += 1)
		{
			cin >> s[i];
			s[i]--;
		}
		
		for (int i = 0; i < N; i += 1)
		{
			cin >> t[i];
			t[i]--;
		}
		
		cout << "Case " << ++ts << ": " << find(N,s,t) << '\n';
	}
	
	return 0;
}















