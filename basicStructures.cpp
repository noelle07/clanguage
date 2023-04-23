#include <stdio.h>
#include <string.h>

struct Buku
{
    char judul[50];
    int harga;
    double rating;
};

int main()
{
    struct Buku buku;
    
    strcpy(buku.judul, "Algorithm");
    buku.harga = 50000;
    buku.rating = 5.0;
    
    printf("%s\n", buku.judul);
    printf("%d\n", buku.harga);
    printf("%lf\n", buku.rating);    
    
    return 0;
}
