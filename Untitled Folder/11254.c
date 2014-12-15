#include <stdio.h>
#include <math.h>



char s[10 * 1024 * 1024] = {0}, out[10 * 1024 * 1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, i, I, j, k, sign, bb, A, B, ii, ans1, ans2, sq;
long long n, l, N;
long p2;

static int int_max(int a, int b) {
    b = a - b;
    a -= b & (b >> 31);
    return a;
}

unsigned long isqrt(unsigned long a) {
    unsigned long rem = 0;
    unsigned long root = 0;

    for (ii = 0; ii < 16; ++ii) {
        root <<= 1;
        rem = ((rem << 2) + (a >> 30));
        a <<= 2;
        ++root;

        if (root <= rem) {
            rem -= root;
            ++root;
        }

        else    --root;
    }
    return (unsigned long)(root >> 1);
}

void readn_signed() {
    sign = 1;
    n = 0;
    while ( s[++count] != '\n' && s[count] != ' ' && s[count] != '\0' ) {
        switch ( s[count] ) {
        case '-' : sign = -1; continue;
        default: n *= 10; n += ( s[count] - '0' );
        }
    }
hell:
    n *= sign;
}


void writen ( long long m ) {
    cnt = -1;
    char tmp[128] = {0};
    do {
        tmp[++cnt] = (char)( m % 10 + 48 );
        m /= 10;
    } while ( m != 0 );
    for (i = cnt; i >= 0; --i) {
        out[++wcount] = tmp[i];
    }
}

int main (int argc, char *argv[]) {

    fread_unlocked(s, sizeof(char), 10 * 1024 * 1024, stdin);
    readn_signed();
    do {
        N = n << 1;
        sq = isqrt(N);

        p2 = 1;
        bb = N;
        while ((bb & 1) == 0) {
            bb >>= 1;
            p2 <<= 1;
        }

        ans1 = 0;
        for (j = p2 * (sq / p2); j > 0; j -= p2) {
            if (N % j == 0) {
                ans1 = j;
                break;
            }
        }
        sq += (sq & 1);
        --sq;
        for (j = sq; j > 0; j -= 2) {
            if (bb % j == 0) {
                ans2 = j;
                break;
            }
        }
        ans1 = int_max(ans1, ans2);
        A = (N / ans1) - ans1;
        A >>= 1;
        --ans1;

        writen (N >> 1);
        out[++wcount] = ' ';
        out[++wcount] = '=';
        out[++wcount] = ' ';
        writen (++A);
        out[++wcount] = ' ';
        out[++wcount] = '+';
        out[++wcount] = ' ';
        out[++wcount] = '.';
        out[++wcount] = '.';
        out[++wcount] = '.';
        out[++wcount] = ' ';
        out[++wcount] = '+';
        out[++wcount] = ' ';
        writen (A + ans1);
        out[++wcount] = '\n';
        readn_signed();

    } while ( n != -1 );

    fwrite_unlocked(out, 1, wcount + 1, stdout);

    return 0;
}
