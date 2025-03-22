#include <bits/stdc++.h>
using namespace std;
//
// Created by TDG on 22/03/2025.
//
// Bai 1: Set & int
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
  set<int> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;
    s.insert(t);
  }
  cout << s.size() << endl;
  for (int i : s)
    cout << i << " ";
}
