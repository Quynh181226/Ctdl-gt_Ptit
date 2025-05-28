//
// Created by TDG on 22/03/2025.
//
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
  // khai bao 1 vector rong
  vector<int> v;
  // push_back: day 1 ptu vao cuoi vector luc nay kich thuoc vector se mo rong len
  v.push_back(5); // 3
  v.push_back(2); // 3 2
  v.push_back(3); // 3 2 5
  // In ra slg ptu trg vector
  cout << v.size() << endl;
  // Duyet cac ptu trg vector tu dau den cuoi

  //
  // C1: Sdung vong for
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;

  //
  // C2: Range-based for loop: for each
  // Eg vs mang a
  int a[4] = {3, 2, 8, 9};
  // Cu moi vong lap lay 1 ptu cua mang a gan cho x
  // Chay den het mang tu dung(stop)
  for (int x : a)
  {
    cout << x << " ";
  }

  // Hoac muon duyet mang a ma muon thay doi gtri
  // Thi khi nay no se thay doi tat ca cac ptu trg mang a = 28
  // Nhg ma bthg thi chi nen duyet = forEach
  for (int &y : a)
  {
    y = 28;
  }
  for (int y : a)
  {
    cout << y << " ";
  }

  //
  // Cach nhap va luu vao trg 1 vector
  vector<int> k;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    // Tao 1 bien tam sau do push bien tam do vao trg vector
    int x;
    cin >> x;
    k.push_back(x);
  }
  for (int x : k)
  {
    cout << x << " ";
  }
  // Neu khai bao nhu bthg thi vector đg rong tuc
  // neu muon cin ttiep vao chi so cua mang thi se bi loi
  //=> Dung cach sau
  //=> Xin cap phat 1 vector co san N ptu
  int d;
  cin >> d;
  vector<int> l(d);
  for (int i = 0; i < d; i++)
  {
    cin >> l[i];
  }
  for (int x : l)
  {
    cout << x << " ";
  }
  //++++>>>>> Co 2 cach nhap ptu vao trg vector
  // 1. push_back
  // 2. tao 1 vetor co san N ptu sau do nhap vao chi so cua mang
}