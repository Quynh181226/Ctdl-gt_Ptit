// Một dãy bít nhị phân 0 - 1 được gọi là xâu nhị phân chẵn nếu số lượng số 1 là số chẵn(tính cả trường hợp không có số 1 nào).
// Cho số nguyên dương n(2 < n < 16).Hãy liệt kê các xâu nhị phân chẵn theo thứ tự từ điển.
// Input
// Chỉ có 1 số n(2 < n < 16)
// Output
// Ghi ra lần lượt các xâu nhị phân chẵn theo thứ tự từ điển, mỗi xâu trên một dòng.
// Các số 0 - 1 trong mỗi xâu cách nhau đúng một khoảng trống.
// Ví dụ
// Input:4
// Output:
// 0 0 0 0
// 0 0 1 1
// 0 1 0 1
// 0 1 1 0
// 1 0 0 1
// 1 0 1 0
// 1 1 0 0
// 1 1 1 1


//HINH NHU 2 BAI NAY LA IN XAU NHI PHAN THEO THU TU TU DIEN
//#include<iostream>
//#include<stdbool.h>
//bool x;
//using namespace std;
//typedef long long int ll;
//void sinh(int*M,int n) {
//    int a = 0;
//    for (int i = n; i >= 1; i--) {
//        if (M[i] == 0) {
//            M[i] = 1; a = 1;
//            for (int j = i + 1; j <= n; j++)M[j] = 0;
//            break;
//        }
//    }
//    if (a == 0)x = true;
//}
//void printf(int* M, int n) {
//    for (int i = 1; i <= n; i++)
//        cout << M[i]; cout << " ";
//}
//int main() {
//    int n; cin >> n;
//    int M[100000] = { 0 };
//    x = false;
//    while (!x) {
//        printf(M, n);
//        sinh(M, n);
//    }
//    cout << endl;
//}
// #include <iostream>
// using namespace std;
//
// int a[100];
//
// void in(int n){
//     for(int i = 0; i<n; i++){
//         cout<<a[i];
//     }
//     cout<<endl;
// }
//
// void quaylui(int k, int n){
//     for(int i = 0; i<= 1; i++)
//     {
//         a[k] = i;
//         if(k == n-1){
//             in(n);
//         }
//         else{
//             quaylui(k+1,n);
//         }
//     }
// }
//
// int main()
// {
// 	int n;
// 	cin>>n;
//
//     quaylui(0, n);
// }

// #include<bits/stdc++.h>
#include<iostream>

using namespace std;

int arr[15], n;

void in() {
    int cnt = 0;
    for (int i=0; i<n;i++) {
        if (arr[i]==1) cnt++;
    }
    if (cnt%2==0) {
        for (int i=0; i<n;i++) {
            cout<<arr[i];
            if (i<n-1) cout<<" ";
        }
        cout<<endl;
    }
}

void quaylui(int b) {
    for (int i=0; i<=1; i++) {
        arr[b]=i;
        if (b==n-1) in();
        else quaylui(b+1);
    }
}

int main() {
    cin>>n;
    if (n>2&&n<16) quaylui(0);
    else return 0;
}