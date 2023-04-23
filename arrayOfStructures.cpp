#include <stdio.h>

struct Buku
{
    char judul[50];
    int harga;
    double rating;    
};

int main()
{
    int n;
    scanf("%d", &n);
    
    Buku buku[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s\n", buku[i].judul);
        scanf("%d\n", &buku[i].harga);
        scanf("%lf", &buku[i].rating);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Judul: %s\n", buku[i].judul);
        printf("Harga: %d\n", buku[i].harga);
        printf("Rating: %.1lf\n", buku[i].rating);
    }
    
    return 0;
}
