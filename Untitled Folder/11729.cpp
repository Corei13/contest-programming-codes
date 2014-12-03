#include <iostream>
#include <deque>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

#define pi pair <int, int>
#define x first
#define y second
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define all(v) (v).begin(), (v).end()

using namespace std;

int T;
int N, cnt;
int A;
pi a[1024];

bool comp ( pi u, pi v)
{
	return u.x + max( u.y, v.x + v.y ) < v.x + max( v.y, u.x + u.y );
}


int main (int argc, char const* argv[])
{

	while ( cin >> N && N )
	{
		for (int i = 0; i < N; i += 1)
		{
			cin >> a[i].x >> a[i].y;
		}
		
		sort(a,a+N,comp);
		
		A = a[0].x+a[0].y;
		for (int i = 1; i < N; i += 1)
		{
			a[i].x += a[i-1].x;
			A = max(a[i].x+a[i].y,A);
		}
		
		cout << "Case " << ++cnt << ": " << A << '\n';
	}
	
	
	
	return 0;
}















