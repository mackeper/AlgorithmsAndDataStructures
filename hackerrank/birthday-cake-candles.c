#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int tallest = 0;
    int cnt = 0;

    int c;
    while(n--) {
        scanf("%d", &c);
        if(c > tallest) {
            tallest = c;
            cnt = 1;
        } else if(c == tallest) {
            cnt++;
        }
    }

    printf("%d\n", cnt);
}
