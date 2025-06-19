//cac ptu co gtri lon hon cac ptu sau no
#include <stdio.h>
// #include<bits/stdc++.h>
// using namespace std;
main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0; i<n-1;i++){
        int check=1;
        for(int j=i+1;j<n;j++){
            if(a[j]>=a[i]){
                check=0;
                break;
           }
        }
        if (check==1) printf("%d ",a[i]);
    }
}