#include<stdio.h>
#include<stdlib.h>
main(){
    int n; scanf("%d",&n);
    int *a = (int *)calloc(n, sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", a+i);
    int f; scanf("%d",&f);
    int check=-1;
    for(int i=0;i<n;i++){
        if(a[i]==f){
            check = i;
            break;
        }
    }
    if(check!=-1)  printf("%d", check);
    else printf("Not Found");
    free(a);
}