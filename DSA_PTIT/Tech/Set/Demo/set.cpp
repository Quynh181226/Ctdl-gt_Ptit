#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
//
// Created by TDG on 22/03/2025.
//
// Set ko co ptu trung nhau .neu cố tình thêm hoặc
// chèn ptu trùng nhau thì set sẽ tự loại bỏ
// Tu dong sap xep theo thu tu tang dan
//
int main()
{
  set<int> s;
  s.insert(1);
  s.insert(6);
  s.insert(0);
  s.insert(4);
  cout << s.size() << endl;
  for (int x : s)
  {
    cout << x << " ";
    // Out
    // 4
    // 0 1 4 6
  }
}