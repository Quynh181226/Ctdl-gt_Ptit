//
// Created by TDG on 25/03/2025.
//
//Cho số nguyên dương N và K. Hãy tính NK modulo 109+7.
//Input:
//Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
//Mỗi test gồm 1 số nguyên N và K (1 ≤ N ≤ 1000, 1 ≤ K ≤ 109).
//Output:
//Với mỗi test, in ra đáp án trên một dòng.
//Ví dụ:
//In-Out:
//2     8
//2 3   16
//4 2
#include<bits/stdc++.h>
int m=1e9+7;
long long power(int n, int k){
    if(k==0) return 1;
    long long x=power(n, k/2);
    if(k%2==0) return x*x%m;
    return n*(x*x%m)%m;
}
using namespace std;
int main(){
    int t, n, k;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        cout<<power(n, k)<<endl;
    }
}