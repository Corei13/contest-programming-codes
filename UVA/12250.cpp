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
    
    map <string, string> f;

    f["HELLO"] = "ENGLISH";
    f["HOLA"] = "SPANISH";
    f["HALLO"] = "GERMAN";
    f["BONJOUR"] = "FRENCH";
    f["CIAO"] = "ITALIAN";
    f["ZDRAVSTVUJTE"] = "RUSSIAN";
    
    int cs = 0;
    string s;
    while (cin >> s && s != "#") {
        cout << "Case " << ++cs << ": " << (f.find(s) == f.end() ? "UNKNOWN" : f[s]) << endl;
    }

    return 0;
}