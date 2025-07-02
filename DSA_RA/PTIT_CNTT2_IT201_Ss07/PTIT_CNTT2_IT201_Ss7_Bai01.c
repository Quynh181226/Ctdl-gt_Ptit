#include <stdbool.h>
#include<stdio.h>
int a[100];
int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble(int n) {
    bool check;
    for (int i=0; i<n-1;i++) {
        check = false;
        for (int j=0; j<n-i-1; j++) {
            if (a[j]>a[j+1]) {
                swap(&a[j],&a[j+1]);
                check = true;
            }
        }
        if (!check) break;
    }
}
void print(int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}
main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    printf("before: ");
    print(n);
    printf("\n");
    printf("after: ");
    bubble(n);
    print(n);
}