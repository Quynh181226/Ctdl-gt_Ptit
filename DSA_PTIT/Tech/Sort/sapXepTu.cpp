//Cho mang a gom n tu. Hay sxep cac tu trg mang A[] tang dan va giam dan ve tu dien sau do in ra man hinh
//Neu bn chua hoc xg string day la cach bn luu mang nay
//Dau vao
//Dong 1 gom N
//Dong 2 gom N ptu trg mang A[]
//Gioi han: 1<=N<=10^6
//Dau ra 
//Dong 1 in ra cac tu theo thu tu tang dan ve phia tu dien
//Dong 1 in ra cac tu theo thu tu giam dan ve phia tu dien
##include<bits/stdc++.h>
#include<iostream>
using namespace std;
//co 2 cach 1 la dung mang 2 la dung vector string
int main(){
    int n; cin>>n;
    string arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    for(string x:arr) cout<<x<<" ";
    cout<<endl;
    sort(arr, arr+n, greater<string>());
    for(string x: arr) cout<<x<<" ";
}