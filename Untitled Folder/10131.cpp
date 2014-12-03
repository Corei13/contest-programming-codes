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

struct E
{
	int W, S, ind;
	E(int _w = 0, int _s = 0, int _i = 0)
	{
		W = _w;
		S = _s;
		ind = _i;
	}
	bool operator < ( const E &o ) const
	{
		return S > o.S;
	}
};

bool mycomp ( E a, E b )
{
	return (a.W < b.W) || (a.W == b.W && a.S < b.S) ;
}

void find_lis(vector<E> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) 
        {
                // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i]) 
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.    
		for (u = 0, v = b.size()-1; u < v;) 
                {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
                // Update b if new value is smaller then previously referenced value 
		if (a[i] < a[b[u]]) 
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	E tmp;
	vector<E> v;
	vector<int> lis, p;
	int ind = 1, w, s;
	
	while (cin >> w >> s)
	{
		v.push_back(E(w,s,ind++));
	}
	if(ind == 1)
	{
		cout << "0\n";
		return 0;
	}
	sort(v.begin(), v.end(), mycomp);
	
	
	find_lis(v, lis);
	p.push_back(v[lis[0]].ind);
	cout << lis.size() << '\n';
	for (int i = 0; i < lis.size(); i += 1)
	{
		cout << v[lis[i]].ind << '\n';
	}

	return 0;
}















