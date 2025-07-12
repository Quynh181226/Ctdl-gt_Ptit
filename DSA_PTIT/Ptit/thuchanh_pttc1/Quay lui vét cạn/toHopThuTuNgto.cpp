//
// Created by TDG on 23/05/2025.
//
// Cho hai số N, K.
// Ta đã biết sẽ có tất cả C(N,K) tổ hợp của K số tự nhiên trong N số tự nhiên đầu tiên, được đánh số thứ tự từ 1 đến C(N,K).
// Ký hiệu C(N,K) là số tổ hợp chập K của N.
// Hãy liệt kê các tổ hợp của K số tự nhiên trong N số tự nhiên đầu tiên và có thứ tự là số nguyên tố.
//
// Input
// Chỉ có 1 dòng ghi hai số N, K (1 < K < N < 20).
//
// Output
// Ghi ra các tổ hợp thoả mãn điều kiện bao gồm cả số thứ tự theo mẫu như trong ví dụ dưới đây.
// Input
// 5 3
// Output
// 2: 1 2 4
// 3: 1 2 5
// 5: 1 3 5
// 7: 2 3 4

#include<iostream>
#include <cmath>
using namespace std;

int n, k, arr[15];
int cnt=0;
bool prime(int x) {
    if (x<2) return false;
    for (int i=2; i<=sqrt(x); i++) {
        if (x%i==0) return false;
    }
    return true;
}

void in() {
    ++cnt;
    if (prime(cnt)) {
        cout<<cnt<<": ";
        for (int i=1; i<=k; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

void quaylui(int i) {
    for (int j=arr[i-1]+1;j<=n-k+i;j++) {
        arr[i]=j;
        if (i==k) in();
        else quaylui(i+1);
    }
}

main() {
    cin>>n>>k;
    if (k<=1||k>=n||n>=20) return 1;
    arr[0]=0;
    quaylui(1);
}