#include <bits/stdc++.h>

using namespace std;

void FFT (int n, const vector <complex <double>> &f, vector <complex <double>> &F, int dir = 1) {
    F.clear();
    F.resize(n);
    copy (f.begin(), f.end(), F.begin());

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) {
            swap (F[i], F[j]);
        }
    }

    const double PI = acos (-1.0);
    for (int l = 1; l <= n / 2; l <<= 1) {
        double theta = (PI * dir) / double(l);
        complex <double> r (cos(theta), sin(theta));

        for (int i = 0; i < n; i += 2 * l) {
            complex <double> w(1.0);
            for (int j = 0; j < l; ++j) {
                complex <double> u = F[i + j], v = F[i + j + l] * w;
                F[i + j] = u + v, F[i + j + l] = u - v;
                w *= r;
            }
        }
    }
    if (dir == -1) {
        for (int i = 0; i < n; ++i) {
            F[i] /= double(n);
        }
    }
}

void Multiply (const vector <complex <double>> &f, const vector <complex <double>> &g, vector <complex <double>> &h) {
    vector <complex <double>> F, G;
    int N = 1;

    while (N < max (f.size(), g.size())) {
        N <<= 1;
    }
    N <<= 1;

    FFT (N, f, F);
    FFT (N, g, G);
    for (int i = 0; i < N; ++i) {
        F[i] *= G[i];
    }
    FFT (N, F, h, -1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        vector <complex <double>> f (200005, 0.0), F;
        f[0] = 1.0;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            f[k] = 1.0;
        }
        Multiply (f, f, F);
        int m, ans = 0;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int a;
            cin >> a;
            if (F[a].real() > .5) {
                ans++;
            }
        }
        cout << ans << endl;
    }
  
  return 0;
}
