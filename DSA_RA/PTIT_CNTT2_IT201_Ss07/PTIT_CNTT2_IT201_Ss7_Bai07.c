#include<stdio.h>
main() {
     int n; scanf("%d",&n);
     int a[n];
     if (n<=0||n>=1000) {
          printf("Invalid");
          return 1;
     }
     for (int i=0; i<n; i++) scanf("%d", &a[i]);
     int pre[n], mid[n], next[n], preCnt=0, midCnt=0, nextCnt=0;
     for (int i=0; i<n; i++) {
          if (a[i]<0) {
               pre[preCnt++]=a[i];
          }else if (a[i]==0) {
               mid[midCnt++]=a[i];
          }else {
               next[nextCnt++]=a[i];
          }
     }
     int cnt=0;
     for (int i=0; i<preCnt; i++) {
          a[cnt++]=pre[i];
     }
     for (int i=0; i<midCnt; i++) {
          a[cnt++]=mid[i];
     }
     for (int i=0; i<nextCnt; i++) {
          a[cnt++]=next[i];
     }
     for (int i=0; i<n; i++) printf("%d ", a[i]);
}