#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>


#define X first
#define Y second


using namespace std;


int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	int N;
	long long m, a, S;
	
	while (cin >> N && N)
	{
		S = 0;
		m = 0;
		for (int i = 1; i <= N; i += 1)
		{
			cin >> a;
			if (m > 0)
			{
				m += a;
			}
			else	m = a;
			S = max(S, m);
		}
		if (S)
		{
			cout << "The maximum winning streak is " << S << ".\n";
		}
		else	cout << "Losing streak.\n";
	}
	
	return 0;
}















