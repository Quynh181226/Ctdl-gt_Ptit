//
// Created by TDG on 16/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

main(){
    int n;
    scanf("%d",&n);

    int *a=(int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int *b=(int *)calloc(100, sizeof (int));

    for(int i=0; i<n;i++) b[a[i]]++;
    for(int i=0; i<100; i++) {
        if (b[i]!=0) printf("Phan tu %d xuat hien %d lan \n", i, b[i]);
    }
}
