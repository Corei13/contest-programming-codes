#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct box {
    int D;
    vector <int> d;

    box () {}

    void input ( int _D ) {
        D = _D;
        int tmp;
        d.clear();
        for (int i = 0; i < D; i += 1) {
            cin >> tmp;
            d.push_back ( tmp );
        }

        sort ( d.begin(), d.end() );
    }

    bool operator < ( const box& o ) {
        return (d[0] < o.d[0]);
    }

    bool operator << ( const box& o ) {
        for (int i = 0; i < D; i += 1) {
            if (d[i] >= o.d[i]) {
                return false;
            }
        }
        return true;
    }

    void print () {
        for (int i = 0; i < D; i += 1) {
            cout << d[i] << ' ';
        }
        cout << '\n';
    }
};

vector <box> B;

int main (int argc, char *argv[]) {
    box tmp;

    ios::sync_with_stdio (false);

    while ( cin >> N >> D ) {
        B.clear();
        for (int i = 0; i < N; i += 1) {
            tmp.input();
            B.push_back (tmp);
        }
        sort ( B.begin(), B.end() );
        for (int i = 0; i < N; i += 1) {
            B[i].print();
        }
    }



    return 0;
}
