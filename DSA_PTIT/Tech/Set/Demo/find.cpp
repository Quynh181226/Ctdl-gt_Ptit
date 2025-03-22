//
// Created by TDG on 22/03/2025.
//
#include<bits/stdc++.h>
using namespace std;
int main(){
  set<int> s={1,2,4,3,8,6};
  set<int>::iterator n=s.find(10);
  if(n==s.end()){
    cout<<"Not Found"<<endl;
  }else{
    cout<<"Found\n";
  }

}