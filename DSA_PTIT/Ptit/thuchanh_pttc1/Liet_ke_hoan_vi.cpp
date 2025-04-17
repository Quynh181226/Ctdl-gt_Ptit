//
// Created by TDG on 16/04/2025.
//

#include<bits/stdc++.h>
using namespace std;
int n, m, a[15], b[15];
void in(){
  for(int i=1;i<=n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  }

void quaylui(int i){
  int j;
  for(j=1;j<=i;j++){
    if(b[j]==0){
      a[i]=j;
      b[j]=1;
      if(i==n-1) in();
      else quaylui(i+1);
      b[j]=0;
    }
  }
}
int main(){
  cin>>n>>m;
  b[m]=1;
  a[n]=m;
  quaylui(1);
}