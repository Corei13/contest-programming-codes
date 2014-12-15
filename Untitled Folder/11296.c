#include <stdio.h>



char s[10 * 1024 * 1024] = {0}, out[10 * 1024 * 1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, i, I, j, k, sign, b[128], notnull;
long long n, l;
int ans[16], max, tmp, tmax, change;

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

void readn() {
    n = 0;
    notnull = 0;
    while ( s[++count] != '\n' && s[count] != ' ' && s[count] != '\0' ) {
        n *= 10; n += ( s[count] - '0' );
        notnull |= 1;
    }
    if ( notnull == 0 ) n = -1;
}

void writen ( long long m ) {
    cnt = -1;
    wcount += log10(m);
    ++wcount;


    do {
        out[wcount - ++cnt] = (char)( m % 10 + 48 );
        m /= 10;
    } while ( m != 0 );
}


int main (int argc, char *argv[]) {

    fread_unlocked(s, sizeof(char), 10 * 1024 * 1024, stdin);

    readn();
    do {
        n >>= 1;
        ++n;
        n += n * n;
        n >>= 1;
        writen ( n );
        out[++wcount] = '\n';
        readn();
    } while (n >= 0);

    fwrite_unlocked(out, 1, wcount + 1, stdout);

    return 0;
}
