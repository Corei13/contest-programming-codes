#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>



#define X first
#define Y second


using namespace std;


int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	int T, C, a, n1, n5, n10, N10, N5, N1, Coke, tmp, blah;
	cin >> T;
	
	for (int t = 0; t < T; t += 1)
	{
		cin >> C >> n1 >> n5 >> n10;
		int ans = 1000000;
		N10 = n10;
		N5 = n5;
		Coke = C;
		N1 = n1;
		for (int k = 0; k <= min(N10,Coke); k += 1)
		{
			for (int l = 0; 2*l <= min(N5,2*(Coke-k)); l += 1)
			{
				tmp = 0;
				n5 = N5;
				n10 = N10;
				C = Coke;
				n1 = N1;
				
				tmp += (k + 2*l);
				n10 -= k;
				n5 -= 2*l;
				n1 += 2*(k+l);
				C -= ( k+l );
				
				while (n10 > 0 && C > 0)
				{
					if (n1 >= 3)
					{
						blah = min( min(n1/3,n10), C );
						tmp += (4*blah);
						n10 -= blah;
						n1 -= 3*blah;
						n5 += blah;
						C -= blah;
					}
					else if (n5 >= 2)
					{
						n5 -= 2;
						tmp += 2;
						n1 += 2;
						C--;
					}
					else	break;
				}
				if (n10 > 0 && C > 0)
				{
					break;
				}
				if (n5 >= 2*C)
				{
					tmp += 2*C;
				}
				else
				{
					a = max ( max ( int(ceil((3*n5 - n1)/8)), 0 ), n5 - C );
					tmp += 2*a;
					n5 -= 2*a;
					C -= a;
					tmp += 4*n5;
					C -= n5;
					tmp += C*8;
				}
				//cout << k << ' ' << l << ' ' << tmp << '\n';
				ans = min(ans, tmp);
			}
			
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}















