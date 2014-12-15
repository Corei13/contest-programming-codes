#include <stdio.h>
#include <stdlib.h>



char s[10 * 1024 * 1024] = {0}, out[10 * 1024 * 1024] = {0}, tmp[1024] = {0};
static int count = -1, wcount = -1;
int cnt = -1, i, t, I, j, K, sign, a[8192];
long long n, l, A;
FILE *in  = fopen ("in.in", "r");

void readn() {
    n = 0;
    while ( s[++count] != '\n' && s[count] != ' ' && s[count] != '\0' ) {
        n *= 10; n += ( s[count] - '0' );
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

int compare (const void *a, const void *b) {
    return ( *(int *)a - * (int *)b );
}


int main (int argc, char *argv[]) {

    fread_unlocked(s, sizeof(char), 10 * 1024 * 1024, in);

    readn();
    do {
        K = n;
        for (I = 0; I < K; I += 1) {
            readn();
            a[I] = n;
        }
        qsort (a, K, 4, compare);
        A = -a[0];
        for (I = 0; I < K; I += 1) {
            A += (K - I) * a[I];
        }
        writen(A);
        out[++wcount] = '\n';
        readn();
    } while (n > 1);

    fwrite_unlocked(out, 1, wcount + 1, stdout);

    return 0;
}
