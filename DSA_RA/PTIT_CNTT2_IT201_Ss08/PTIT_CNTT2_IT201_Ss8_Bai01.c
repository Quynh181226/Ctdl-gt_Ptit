#include<stdio.h>
main() {
    int n; scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    int x; scanf("%d",&x);
    int check=0;
    for (int i=0; i<n; i++) {
        if (a[i]==x) {
            printf("Pos: %d ",a[i]);
            check=1;
            break;
        }
    }
    if (!check) printf("Invalid el");
}