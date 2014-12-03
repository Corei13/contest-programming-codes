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

int T;
int N;
string s[16];

char S ( int i, int j )
{
	if (i >= 0 && j >= 0 && i < N && j < N)
		return s[i][j];
	return '.';
};
		
int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	cin >> T;
	
	for (int ts = 1; ts <= T; ts += 1)
	{
		cin >> N;	
		
		for (int i = 0; i < N; i += 1)
		{
			cin >> s[i];
		}
		
		for (int i = 0; i < N; i += 1)
		{
			for (int j = 0; j < N; j += 1)
			{
				if (s[i][j] == '.')
				{
					for (char k = 'A'; k <= 'Z'; k++)
					{
						if(S(i-1,j) != k && S(i,j-1) != k && S(i,j+1) != k && S(i+1,j) != k)
						{
							s[i][j] = k;
							break;
						}
					}
				}
			}
		}
		
		cout << "Case " << ts << ":\n";
		for (int i = 0; i < N; i += 1)
		{
			cout << s[i] << '\n';
		}
	}
	
	return 0;
}















