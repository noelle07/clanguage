//#include <stdio.h> 
//
//int main(){
//	FILE *fp = fopen("./tetdata.in", "r");
//	
//	long long int t;
//	fscanf(fp, "%lld", &t);
//	getchar();
//	for(int i = 0; i <= t; i++){
//		long int n,a,b;
//		fscanf(fp, "%d %d %d", &n, &a, &b);
//		getchar();
//		char s[n++], *c = s;
//		fscanf(fp, "%*c%[01]", s);
//		getchar();
//		int p, q = 0;
//		do {
//            if (*c == '0') continue;
//            for (p = 0; *c == '1' && *c++ && p++;);
//            p >= a && p <= b && p++;
//        } 
//		while (*c++);
//        printf("Case #%ld: %lld\n", i, q);
//    }
//
//	return 0;
//}

#include <stdio.h>

int main() {
    FILE *fp = fopen("./testdata.in", "r");

    int t, n, a, b;
    fscanf(fp, "%d", &t);

    for (int i = 0; i < t;) {
        fscanf(fp, "%d%d%d", &n, &a, &b);

        char S[++n], *c = S;
        fscanf(fp, "%*c%[01]", S);

        int p, q = 0;
        do {
            if (*c == '0') continue;

            for (p = 0; *c == '1' && *c++ && ++p;);

            p >= a && p <= b && ++q;
        } while (*c++);

        printf("Case #%d: %d\n", ++i, q);
    }

    return 0;
}
