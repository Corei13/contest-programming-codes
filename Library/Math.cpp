/*
    Implementation of Fast Fourier Transformation algorithm

    Input:
        - n, size of the input sequence, should be a power of 2
        - f, the input sequence
        - dir, 1 for Fourier transformation, -1 for inverse Fourier transformation

    Output:
        - F, Fourier transformation of f

    Complexity:
        - O(nlog(n))

    Tested Problems:
        - UVA: 12879
*/

void FFT (int n, const vector <complex <double>>& f, vector <complex <double>>& F, int dir = 1) {
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

/*
    Implementation of polynomial multiplication algorithm

    Input:
        - f, g, polynomials to be multipled

    Output:
        - h, h[n] := f[0] * g[n] + ... + f[n] * g[0]

    Complexity:
        - O(nlog(n))

    Tested Problems:
        - UVA: 12879
*/

void Multiply (const vector <complex <double>>& f, const vector <complex <double>>& g, vector <complex <double>>& h) {
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