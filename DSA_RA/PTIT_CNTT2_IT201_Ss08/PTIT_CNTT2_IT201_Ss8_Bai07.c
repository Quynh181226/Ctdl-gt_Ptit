#include<stdio.h>
int partition(int a[], int l, int r) {
    int pivot = a[r], i = l - 1, tmp;
    for (int j = l; j <= r - 1; j++) {
        if (a[j]<pivot) {
            i++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;
    return i + 1;
}
void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}
main() {
    int n; scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
}