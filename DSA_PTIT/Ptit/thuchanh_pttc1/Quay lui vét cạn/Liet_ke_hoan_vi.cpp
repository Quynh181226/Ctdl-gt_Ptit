//
// Created by TDG on 16/04/2025.
//
// Cho hai số N và M với 0 < M ≤ N < 10;
// Hãy liệt kê các hoán vị của N số nguyên dương đầu tiên mà số M luôn đứng cuối
// Các hoán vị thỏa mãn cần liệt kê theo thứ tự từ điển.
// Input
// Chỉ có một dòng ghi hai số N và M
// Output
// Liệt kê lần lượt các hoán vị thỏa mãn. Mỗi hoán vị trên một dòng.
// Input
// 4 2
// Output
// 1 3 4 2
// 1 4 3 2
// 3 1 4 2
// 3 4 1 2
// 4 1 3 2
// 4 3 1 2
#include<bits/stdc++.h>
using namespace std;
int n, m, b[15], a[15];
void in(){
  for(int i=1;i<=n;i++){
    cout<<b[i]<<" ";
  }
  cout<<endl;
  }

void quaylui(int i){
  int j;
  for(j=1;j<=n;j++){
    if(a[j]==0){
      b[i]=j;
      a[j]=1;
      if(i==n-1) in();
      else quaylui(i+1);
      a[j]=0;
    }
  }
}
main(){
  cin>>n>>m;
  a[m]=1;
  b[n]=m;
  quaylui(1);
}