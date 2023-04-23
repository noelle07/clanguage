#include <stdio.h>

int main() {
    FILE *fp = fopen("./testdata.in", "r");

    int t;
    fscanf(fp, "%d", &t);
    for (int i = 0; i < t; i++) {
        char X[101], *x;
        fscanf(fp, "%*c%s", X);
        int n;
        fscanf(fp, "%d", &n);
        char Y[27] = {0};
        for (int j = 0; j < n; j++) {
            char A, B;
            fscanf(fp, "%*c%c%*c%c", &A, &B);
            x = X;
            do *x == A && !Y[A - 'A'] && (*x = B);
            while (*x++);
            *(Y + A - 'A') = 1;
        }
        int M[26] = {0}, *m = M;
        x = X;
        do *(m + *x - 'A') += 1;
        while (*++x);
        do *m && printf("%c %d\n", (char) (m - M + 'A'), *m);
        while (++m < M + 26);
    }
    
	return 0;
}
