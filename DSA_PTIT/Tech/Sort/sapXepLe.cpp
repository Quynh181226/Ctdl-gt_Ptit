//Sxep le
//Cho mang A[] gom N ptu sxep sao cho so nao co nh so le hon thi dung trc
//trg trg hop nh so co cg chu so le thi so nao nho hon se dung trc 
//In...
//Gioi han
//1<=N<=10^6
//0<=A[i]<=10^9
//Out: In ra cac so sau khi sap xep
#include<bits/stdc++.h>
using namespace std;
int le(int n){
    int cnt=0;
    while (n!=0)
    {
        if(n%2==1){
            cnt++;
        }
        n/=10;
    }
    return cnt;
}
bool cmp(int x, int y){
    if(le(x)!=le(y)){
        //Ưu tiên số có le() lớn hơn đứng trước, nếu bằng nhau thì số nhỏ hơn đứng trước.
        //giam dan va = thi nho hon dung trc
        return le(x)>le(y);
    }else{
        return x<y;
    }
} 
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a, a+n, cmp);
    for(int x:a) cout<<x<<" ";
}