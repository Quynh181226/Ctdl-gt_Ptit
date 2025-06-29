#include<stdio.h>
#include<stdlib.h>
int a[50];
void minMax(int i, int j, int *min, int *max){
    //start, end, đk dung
    if(i>j) return;
    if(a[i]<*min) *min=a[i];
    if(a[i]>*max) *max=a[i];
    minMax(i+1, j, min, max);
}
main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int min=a[0],max=a[0];
    minMax(0,n-1,&min,&max);
    printf("%d %d",min, max);
}