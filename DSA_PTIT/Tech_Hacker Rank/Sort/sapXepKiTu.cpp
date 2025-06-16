//Sxep ki tu
//Cho mang A[] gom N ktu la chu cai in hoa, in thg or chu so
//Hay sxep cac ky tu trg mang A[] tang dan va giam dan ve tu dien sau do in ra man hinh
//Dau vao
//Dong 1 gom N
//Dong 2 gom N ptu trg mang A[]
//Gioi han: 1<=N<=10^64
//Dau ra
//Dong 1 in ra cac ky tu theo thu tu tang dan ve tu dien
//Dong 2 in ra cac ky tu theo thu tu giam dan ve tu dien
//Input: 
//6
//2 8 t e c h
//Ouput
//2 8 c e h t
//t h e c 8 2
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    char arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    for(char x:arr) cout<<x<<" ";
    cout<<endl;
    sort(arr, arr+n, greater<char>());
    for(char x: arr) cout<<x<<" ";
}