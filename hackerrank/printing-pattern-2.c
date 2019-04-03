#include <stdio.h>

#define ABS(x) (x < 0 ? x*-1 : x)
#define MAX(a, b) (a > b ? a : b)

int main() 
{

    int n;
    scanf("%d", &n);

    for (int y = 1; y <= n+n-1; y++) {
        for (int x = 1; x <= n+n-1; x++) {
            printf("%d ", MAX(ABS((n-x))+1, ABS((n-y))+1));
        }
        printf("\n");
    }

    return 0;
}
