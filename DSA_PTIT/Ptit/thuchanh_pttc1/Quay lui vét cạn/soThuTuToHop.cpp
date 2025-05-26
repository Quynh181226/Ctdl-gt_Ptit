//
// Created by TDG on 22/05/2025.
//
// Cho một tổ hợp chập K của N số nguyên dương đầu tiên (2 < K < N < 15).
// Hãy xác định xem đó là tổ hợp thứ bao nhiêu nếu liệt kê tất cả các tổ hợp theo thứ tự tăng dần (tính từ 1).
//
// Input:
// Dòng đầu ghi số T là số bộ test (T < 10)
// Mỗi bộ test gồm 2 dòng
// Dòng đầu ghi 2 số nguyên dương N và K (2 < K < N < 15)
// Dòng tiếp theo ghi một tổ hợp chập K của các số nguyên dương từ 1 đến N.
//
// Output:
// Với mỗi bộ test, ghi ra trên một dòng số thứ tự của tổ hợp (tính từ 1, theo thứ tự liệt kê tăng dần).
//
// Input	                    Output
// 2 6 4 1 3 5 6 6 4 2 3 4 6	9 12

// mảng lưu tổ hợp hiện tại mảng lưu tổ hợp đâù va cần tìm số thứ tự
#include<iostream>
using namespace std;

int n, k, cnt;
int arr[15], temp[15];
bool check;
void Solve() {
    cnt++;
    for (int i=1;i<=k;i++) {
        if (arr[i] != temp[i]) return;
    }
    check = true;
}
void quaylui(int i) {
    if (check) return;
    //xdinh gtri nho nhat va lon nhat ma arr[i] co the nhan
    for (int j=arr[i-1]+1; j<=n-k+i;j++) {
        arr[i]=j;
        if (i==k) Solve();
        else quaylui(i+1);
    }
}
int main() {
    int t; cin>>t;
    if (t>=10) return 1;
    while(t--) {
        cnt=0;
        check = false;
        cin>>n>>k;
        if (k<=2||k>=n||n>=15) {
            for (int i = 1; i <= k; i++) cin >> temp[i];
            cout << endl;
            continue;
        }
        for (int i=1;i<=k;i++) cin>>temp[i];
        quaylui(1);
        cout<<cnt<<endl;
    }
    return 0;
}