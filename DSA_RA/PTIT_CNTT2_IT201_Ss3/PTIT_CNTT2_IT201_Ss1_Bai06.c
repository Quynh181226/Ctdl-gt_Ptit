#include<stdio.h>
int main(){
int n, m;
scanf("%d",&n);

if(n<=0||n>1000) return 1;
int *a = (int*)malloc(n*sizeof(int));
if(a==NULL) return 1;

for(int i=0;i<n;i++) scanf("%d",&a[i]);

scanf("%d",&m);
int *b = (int*)realloc(a, (n+m)*sizeof(int));
if(b==NULL){
 free(a);
 return 1;
}

for(int i=0;i<n+m;i++) scanf("%d",&a[i]);
n+=m;
for(int i=0;i<n;i++) scanf("%d",&a[i]);
}