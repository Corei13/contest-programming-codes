#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <deque>

using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%M)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;

int N;

int f ( char a, char b )
{
    if ( a == '0' )
        return 26;
    if ( b == '+' )
        return a-'A';
    return 52-(a-'A');
}

int main (int argc, char const* argv[])
{
    ios::sync_with_stdio(false);

    while(cin >> N) {
        VVI w(53, VI(53,0));
        string S;
        VI v(4);

        for (int i = 0; i < N; i += 1)
        {
            cin >> S;
            for (int i = 0; i < 4; i += 1)
            {
                v[i] = f(S[2*i], S[2*i+1]);
            }
            for (int i = 0; i < 4; i += 1)
                for (int j = 0; j < 4; j += 1)
                    if(i != j && v[i] != 26 && v[j] != 26)
                        w[v[i]][v[j]] = 1;
        }
        for (int k = 0; k < 53; k += 1)
            for (int i = 0; i < 53; i += 1)
                for (int j = 0; j < 53; j += 1)
                    w[i][j] |= w[i][k]*w[52-k][j];
        bool bounded = true;
        for (int i = 0; i < 26; i += 1)
            if (w[i][52-i])
            {
                bounded = false;
                break;
            }
        if (bounded)
            cout << "bounded\n";
        else
            cout << "unbounded\n";
    }
        
    return 0;
}





