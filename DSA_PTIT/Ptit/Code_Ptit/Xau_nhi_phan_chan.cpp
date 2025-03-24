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