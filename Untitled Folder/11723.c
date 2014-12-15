#include <stdio.h>
#include <math.h>

const int coin[5] = { 1, 5, 10, 25, 50 };
char s[10 * 1024 * 1024] = {0}, out[10 * 1024 * 1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, k, sign, b[128];
long long n, l;

void readn() {
    sign = 1;
    n = 0;
    ++count;
    while ( s[count] == '\n' || s[count] == ' ' ) {
        ++count;
    }
    --count;
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
    for (k = cnt; k >= 0; --k) {
        out[++wcount] = tmp[k];
    }
}

int main (int argc, char *argv[]) {
    int N, R, K, T = 1, A;

    fread_unlocked(s, sizeof(char), 100 * 1024, stdin);

    readn();
    R = n;
    readn();

    do {
        N = n;

        K = (R - 1) / N;
        out[++wcount] = 'C';
        out[++wcount] = 'a';
        out[++wcount] = 's';
        out[++wcount] = 'e';
        out[++wcount] = ' ';
        writen(T++);
        out[++wcount] = ':';
        out[++wcount] = ' ';

        if (K > 26) {
            out[++wcount] = 'i';
            out[++wcount] = 'm';
            out[++wcount] = 'p';
            out[++wcount] = 'o';
            out[++wcount] = 's';
            out[++wcount] = 's';
            out[++wcount] = 'i';
            out[++wcount] = 'b';
            out[++wcount] = 'l';
            out[++wcount] = 'e';
        } else {
            writen(K);
        }
        out[++wcount] = '\n';

        readn();
        R = n;
        readn();
    } while ( n != 0 );

    fwrite_unlocked(out, 1, wcount + 1, stdout);

    return 0;
}
