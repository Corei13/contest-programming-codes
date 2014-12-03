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
#define y second.first
#define id second.second
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define all(v) (v).begin(), (v).end()

using namespace std;

int T;
int N;
long long L, t;
pair<long long, pi> a[10500], b[10500];
int col[10500], f[10500];
string ch;

int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	cin >> T;
	
	for (int ts = 1; ts <= T; ts += 1)
	{
		cin >> L >> t >> N;
		
		for (int i = 0; i < N; i += 1)
		{
			cin >> a[i].x >> ch;
			a[i].y = ( ch == "R" ) ? 1 : -1;
			a[i].id = i;
			col[i] = 0;
		}
		
		sort(a,a+N);
		
		for (int i = 0; i < N; i += 1)
		{
			f[a[i].id] = i;
		}
		
		for (int i = 0; i < N; i += 1)
		{
			a[i].x += t*a[i].y;
		}
		
		sort(a,a+N);
		
		for (int i = 0; i < N; i += 1)
		{
			b[i] = a[f[i]];
			if ( ( f[i] > 0 && a[f[i]].x == a[f[i]-1].x ) || ( f[i] < N-1 && a[f[i]].x == a[f[i]+1].x ) )
			{
				col[i] = 1;
			}
		}
		cout << "Case #" << ts << ":\n";

		for (int i = 0; i < N; i += 1)
		{
			if (b[i].x < 0 || b[i].x > L)
			{
				cout << "Fell off\n";
			}
			else if(col[i])
			{
				cout << b[i].x << " " << "Turning" << '\n';
			}
			else
				cout << b[i].x << " " << ( b[i].y == 1 ? 'R' : 'L' ) << '\n';
		}
		cout << '\n';
	}
	
	return 0;
}















