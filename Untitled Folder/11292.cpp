#include <iostream>
#include <deque>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define all(v) (v).begin(), (v).end()

using namespace std;

int T;
int N, M, cnt;
deque<long long> a, b;
long long x, A;

int main (int argc, char const* argv[])
{

	while ( cin >> N >> M && N && M )
	{
		a = deque<long long>(N);
		b = deque<long long>(M);
		
		for (int i = 0; i < N; i += 1)
		{
			cin >> a[i];
		}
		
		for (int i = 0; i < M; i += 1)
		{
			cin >> b[i]; 
		}
		
		sort(all(a));
		sort(all(b));
		
		cnt = 0;
		A = 0;
		
		for (int i = 0; i < M; i += 1)
		{
			if( cnt < N && b[i] >= a[cnt])
				cnt++, A += b[i];
		}
		if(cnt == N)
			cout << A << '\n';
		else
			cout << "Loowater is doomed!\n";
	}
	
	
	
	return 0;
}















