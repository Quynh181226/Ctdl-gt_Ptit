//Cho mang A[] gom N ptu sxep sao cho so nh chu so 0,6 or 8 hon dung trc 
//neu co cung so lg chu so 0, 6, 8 thi so nao nho hon se dung trc
//dau vao, gioi han, dau ra same cac bai trc
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//function dem so lg chu so 0,6,8 cua n 
int count1(int n){
    if(n==0) return 1;//giải thích dòng này
    int cnt=0;
    while(n!=0){
        int r=n%10;
        if(r==0||r==6||r==8){
            cnt++;
        }
        n/=10;
    }
    return cnt;
}
bool cmp(int x, int y){
    if(count1(x)!=count1(y)){
        return (x)<count(y);
    }else{
        return x>y;
    }
}
int main(){
    int n; cin>>n;
    char arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    for(char x:arr) cout<<x<<" ";
}