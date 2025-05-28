#include <bits/stdc++.h>
using namespace std;
//
// Created by TDG on 22/03/2025.
//
// Bai 1: Map & int
// Cho mang A[] gom N ptu so nguyen int, bn hay loc ra cac gtri khac nhau
// trg mang va in ra theo thu tu tang dan
// Input: dong dau tien la so nguyen N
// Dong tiep theo gom N so nguyen A[i]
// Giới hạn :
// 1≤ N ≤ 10^5
//-10^9 ≤ A[i] ≤ 10^9
// Output:
// Dong 1 in ra slg so nguyen khac nhau trg mang
// Dong 2 in ra cac so nguyen khac nhau theo thu tu tang dan
// Sample Input 0
// 5
// 2 1 2 1 3
// Sample Output 0
// 3
// 1 2 3
int main()
{
    map<int, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        m[t]++;
    }
    cout << m.size() << endl;
    for (auto &p : m)
        cout << p.first << " ";
}
// for(auto& p : m)
// auto& p: Sử dụng auto để tự động suy ra kiểu của p, ở đây là pair<const int, int>
//& để lấy tham chiếu, tránh sao chép không cần thiết
// m: Duyệt qua map, mỗi phần tử là một cặp {key, value}
// Mỗi p trg vòng lặp
// p.first: Là key (số duy nhất).
// p.second: Là value(tần suất, không dùng ở đây)
// In key : cout << p.first << " ";
// In key của mỗi cặp, tức là các phần tử duy nhất, theo thứ tự tăng dần (vì map tự động sắp xếp theo key).
