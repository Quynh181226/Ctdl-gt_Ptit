//
// Created by TDG on 17/05/2025.
//
//Cach ham de quy hdong, ky thuat de quy

//1. Đk dừng
//2. Cthuc truy hoi

#include<bits/stdc++.h>
using namespace std;

//De: Tinh tong S(n)=1+2+3+4+...+n
//Bộ nhớ stack lưu các trang thái cuủa hàm, tham số của hàm,địa chỉ trả về,..
//Kiểu gọi tong 5 goi tong 4,3,2,1 m tong 1=1 co cau tloi roi thi no se quay lai tinh gtri cua cac tong con lai
//Phải có bài toán con nhỏ nhất như n=1 chg han thi nó se goi xg sẽ có điểm dừng còn nếu ko nó sẽ chạy mãi ma cho đến khi bộ nhớ stack b tràn_stack over flow....
//Cứ gọi n nhỏ hơn và ko có điểm dừng
//-43162 khi gọi từ 5
int tong(int n) {
    if (n == 1) return 1;
    else return n+tong(n-1);
}
void hello() {
    cout<<"Hello World \n";
    hello();
}

//De: n! = n*(n-1)*(n-2)*...*1
int gt(int n) {
    if (n==0) return 1;
    else return n*gt(n-1);
}

 long long fibo(int n) {
    if (n<=1) return n;
    else return fibo(n-1)+fibo(n-2);
}

int nCk(int n, int k) {
    if (k==0||n==k) return 1;
    else return nCk(n-1, k)+nCk(n-1, k-1);
}
int main() {
    int n;
    cin >> n;
    cout << tong(n) << endl;
    return 0;

    // hello();
    // return 0;

    cout<<gt(5)<<endl;

    //dung fibo = de quy chay rat lau co the len den 2^n , quy hoach dong: nhanh
    // cout<<fibo(92)<<endl;
    // return 0;


    // cout<<nCk(10, 2)<<endl; = 45
    // return 0;

}
