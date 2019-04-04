#include <stdio.h>

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < n; i++) {
      printf("%d ", nums[(i+d)%n]);
    }
    printf("\n");
    return 0;
}
