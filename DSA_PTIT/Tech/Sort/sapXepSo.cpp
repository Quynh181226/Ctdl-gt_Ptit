//Sxep phuc tap thi dung comparation function
//no giong vs greater ne nhung bay h mk phai tu di xdung no
//true: neu x dung trc y sau khi sxep => true
//flase: neu x dung sau y sau khi sxep => flase
//vi sao lai phai co 2 tham so x va y ư vi hieu don gian muon so sanh ta phai so sanh = cap so kieu so nay so sanh vs so kia
//=> la cap so dc so sanh vs nhau roi dem di sxep

//B1: mk muon sxep mang ntn?
//B2: if x muon dung trc y theo thu tu sxep do thi mk se can dk j va if dkien do tman => return true
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//no co 2 tso va kieu dlieu cua 2 tso day se t.ung vs kieu dlieu cua mang 
//eg: sxep theo tong chu so tang dan 
int tong(int n){
    int sum=0;
    while (n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
bool cmp(int x, int y){
    return tong(x)<tong(y);
}
bool cmp1(int x, int y){
    return x<y;
}
bool cmp2(int x, int y){
    if(x<y){
        return true;
    }else{
        return false;
    }
}
bool cmp(int x, int y) return abs(x)<abs(y);
int main(){
    int n; cin>>n;
    char arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    for(char x:arr) cout<<x<<" ";
    cout<<endl;
    sort(arr, arr+n, greater<char>());
    // comparation function
    // sort(arr, arr+n, cmp);
    for(char x: arr) cout<<x<<" ";
}