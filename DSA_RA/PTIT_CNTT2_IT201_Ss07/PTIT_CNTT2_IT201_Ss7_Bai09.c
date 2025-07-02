#include<stdio.h>
#include <stdlib.h>

int ascen(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int descen(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}
main() {
    int n; scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    int even[n], odd[n], evenCnt=0, oddCnt=0;
    for (int i=0; i<n; i++) {
        if (a[i]%2==0) {
            even[evenCnt++] = a[i];
        }else {
            odd[oddCnt++] = a[i];
        }
    }
    qsort(even, evenCnt, sizeof(int), ascen);
    qsort(odd, oddCnt, sizeof(int), descen);
    for (int i=0; i<evenCnt; i++) {
        a[i] = even[i];
    }
    for (int i=0; i<oddCnt; i++) {
        a[evenCnt+i]=odd[i];
    }
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}