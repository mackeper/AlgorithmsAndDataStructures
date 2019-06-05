#include <stdio.h>

int a, b, c, nth;

static int solve(int n) {
        if (n == 1) return a;
        if (n == 2) return b;
        if (n == 3) return c;
        return solve(n-1) + solve(n-2) + solve(n-3);
}

int main(void) {
        scanf("%d %d %d %d", &nth, &a, &b, &c);
        printf("%d\n", solve(nth));
        return 0;
}
