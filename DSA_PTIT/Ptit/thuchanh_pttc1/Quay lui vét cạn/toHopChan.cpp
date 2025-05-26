//
// Created by TDG on 22/05/2025.
//
// Cho hai số n và k với k < n. Một tổ hợp chập k của n số nguyên dương đầu tiên được gọi là tổ hợp chẵn nếu tổng các giá trị số trong tổ hợp là một số chẵn.
// Viết chương trình liệt kê các tổ hợp chẵn có k phần tử của n số nguyên dương đầu tiên theo thứ tự từ điển.
// Input: Chỉ có 1 dòng ghi 2 số n và k (1 < k < n < 16).
// Output: Ghi ra lần lượt các tổ hợp chẵn tìm được theo thứ tự từ điển, mỗi tổ hợp trên một dòng. Các số cách nhau đúng một khoảng trống.
// Ví dụ
// Input
// 5 3
// Output
// 1 2 3
// 1 2 5
// 1 3 4
// 1 4 5
// 2 3 5
// 3 4 5
#include<iostream>
using namespace std;

int n, k, arr[15];
void in() {
    for (int i=1; i<=k;i++) {
        cout<<arr[i];
        if (i<k) cout<<" ";
    }
    cout<<endl;
}

void sumEven() {
    int sum = 0;
    for (int i=1; i<=k;i++) {
        sum += arr[i];
    }
    if (sum%2==0) {
        in();
    }
}
void quaylui(int i) {
    for (int j=arr[i-1]+1; j<=n-k+1; j++) {
        arr[i]=j;
        if (i==k) sumEven();
        else quaylui(i+1);
    }
}
int main() {
    cin>>n>>k;
    if (k<=1||k>=n||n>=16) return 1;
    quaylui(1);
    return 0;
}