#include <stdio.h>
int sum(int n) {
    if (n==0) return 0;
    return (n%10) + sum(n/10);
}

main() {
    int n; scanf("%d",&n);
    if (n<=0) {
        printf("Invalid");
        return 0;
    }
    printf("%d", sum(n));
}
