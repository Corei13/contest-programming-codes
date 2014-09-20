#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<ll, ll> PI;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        string s;
        cin >> s;
        if (s == "1" || s == "4" || s == "78") {
            cout << '+' << endl;
        } else if (sz(s) >= 3 && s.substr(sz(s)-2) == "35") {
            cout << '-' << endl;
        } else if (sz(s) >= 3 && s.front() == '9' && s.back() == '4') {
            cout << '*' << endl;
        } else if (s.substr(0, 3) == "190") {
            cout << '?' << endl;
        }
    }

    return 0;
}