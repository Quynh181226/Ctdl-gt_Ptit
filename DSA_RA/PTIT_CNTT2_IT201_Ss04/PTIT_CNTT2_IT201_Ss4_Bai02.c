#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
main(){
    int n; scanf("%d",&n);
    int *a = (int *)calloc(n, sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", a+i);
    int f=a[0];
    for(int i=1;i<n;i++) {
        if(a[i]>f) {
            f=a[i];
        }
    }
    bool check = false;
    for(int i=0;i<n;i++){
        if(a[i]==f){
            printf("%d", i);
            check = true;
            break;
        }
    }
    if(!check){
        printf("Not Found");
    }
    free(a);
}