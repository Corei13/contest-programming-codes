#include <bits/stdc++.h>

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
typedef vector<VVL> VVVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int n[2], cs = 0;
    while (cin >> n[0] >> n[1]) {
        deque<ll> a[2];
        a[0] = deque<ll> (n[0]), a[1] = deque<ll> (n[1]);
        for (auto& i : a[0]) {
            cin >> i;
        }
        for (auto& i : a[1]) {
            cin >> i;
        }
        sort(all(a[0]), greater<ll>());
        sort(all(a[1]), greater<ll>());
        a[0].push_back(0);
        a[1].push_back(0);
        int curr = 0;
        while (0 < n[curr] && 0 < n[!curr]) {
            if (n[curr] > 1 && a[curr][0] + a[curr][1] > a[!curr][0] + a[!curr][1]) {
                a[curr][1] += a[curr][0];
                a[curr].pop_front();
                a[curr].push_back(0);
                n[curr]--;
            } else if (a[curr][0] > a[!curr][0]) {
                a[!curr].pop_front();
                n[!curr]--;
            } else {
                a[curr][1] += a[curr][0];
                a[curr].pop_front();
                a[curr].push_back(0);
                n[curr]--;
            }
            curr ^= 1;
        }
        if (n[0]) {
            cout << "Case " << ++cs << ": Takeover Incorporated" << endl;
        } else {
            cout << "Case " << ++cs << ": Buyout Limited" << endl;
        }
    }

    return 0;
}