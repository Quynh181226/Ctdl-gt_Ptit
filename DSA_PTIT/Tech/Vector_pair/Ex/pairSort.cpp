//Cho mang A[] gom N diem trg he truc toa do Oxy,
//hay sxep cac diem nay theo khoang cách ve goc toa do 
//tang dan, neu 2 diem có cung khoang cach toi goc toa do 
//thi in ra theo hoanh do tang dan, neu ttuc 2 diem nay 
//co cung hoanh do thi in ra theo thu tu tung do tang dan
//Dau vao: 
//Dong dau tien la N: so luong diem
//N dong tiep theo moi dong la 2 so nguyen x, y tuong ung vs hdo va tung do
//Gioi han:
//1<=N<=10^5
//-1000<x,y<=1000
//Dau ra: In ra cac diem sau khi sxep
#include<bits/stdc++.h>
using namespace std;
//Sap xep 1 mang pair
typedef pair<int, int> ii;
#define fi first
#define se second

//comparator
//tinh khoang cach cua 2 thang nay den goc toa do
bool cmp(ii x, ii y){
    int kcach1=x.fi*x.fi+x.se*x.se;
    int kcach2=y.fi*y.fi+y.se*y.se;
    if(kcach1!=kcach2) return kcach1<kcach2;
    if(x.fi!=y.fi) return x.fi<y.fi;
    return x.se<y.se;
}
int main(){
    int n; cin>>n;
    ii a[n];
    for(int i=0;i<n;i++) cin>>a[i].fi>>a[i].se;
    sort(a, a+n,cmp);
    for(ii x:a) cout<<x.fi<<" "<<x.se<<endl;
}