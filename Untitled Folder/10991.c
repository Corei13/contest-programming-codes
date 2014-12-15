#include <stdio.h>
#include <math.h>




char s[10 * 1024 * 1024] = {0}, out[10 * 1024 * 1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, i, I, j, k, sign, b[128];
long long n, l;
double f, x, y, z, ans, R;
long Pow10;

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
    while ( s[++count] != '\n' && s[count] != ' ' && s[count] != '\0' ) {
        n *= 10;
        n += ( s[count] - '0' );
    }
}

void readf() {
    f = 0;
    Pow10 = 10;

    while ( s[++count] != '.' ) {
        if (  s[count] == '\n' || s[count] == ' ' || s[count] == '\0' ) return;
        f *= 10;
        f += ( s[count] - '0' );
    }
    while ( s[++count] != '\n' && s[count] != ' ' && s[count] != '\0' ) {
        f += ( s[count] - '0' ) / (double)(Pow10);
        Pow10 *= 10;
    }
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

void __writen ( long long m ) {
    cnt = -1;
    char tmp[128] = {0};
    do {
        tmp[++cnt] = (char)( m % 10 + 48 );
        m /= 10;
    } while ( cnt < 5 );
    for (i = cnt; i >= 0; --i) {
        out[++wcount] = tmp[i];
    }
}

int main (int argc, char *argv[]) {

    fread_unlocked(s, sizeof(char), 64 * 1024, stdin);

    readn();
    int i, t = n;
    for (I = 0; I < t; I += 1) {
        readf();
        x = f;
        readf();
        y = f;
        readf();
        z = f;
        ans = sqrt(x * y * z * (x + y + z)) - 0.5 * ( x * x * acos( 1 - 2 * y * z / ( (x + y) * (z + x) ) ) + y * y * acos( 1 - 2 * x * z / ( (x + y) * (z + y) ) ) + z * z * acos( 1 - 2 * x * y / ( (x + z) * (z + y) ) ) ) ;
        writen ( (int)ans );
        out[++wcount] = '.';
        __writen ( (long long)( ans * 1000000 + 0.5 ) );
        out[++wcount] = '\n';
    }

    fwrite_unlocked(out, 1, wcount + 1, stdout);

    return 0;
}
