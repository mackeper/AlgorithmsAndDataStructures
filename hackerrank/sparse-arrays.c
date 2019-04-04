#include <stdio.h>
#include <string.h>

int main() {

    char s[1000][21];
    int n, q;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        char qs[21];
        scanf("%s", qs);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if(!strcmp(qs,s[i])) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
