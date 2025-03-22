#include <bits/stdc++.h>
#include <vector>     //vector
#include <algorithm>  //sort
#include <functional> //greater(1 compeater > (lớn hơn) dùng dễ so sanh giảm dần 14>12>11
using namespace std;
using ll = long long;
//
// Created by TDG on 22/03/2025.
//

// Input:
// Dong 1 la N : slg ptu trg vector
// Dong 2 N so trg vector
// Gioi han
// 1<=N<=1000
// Cac ptu trg vector la so int
// Output:
// In ra cac snt trg day theo ttu xhien
// Eg:
// in
//     15
//     9 6 10 15 4 9 4 3 17 4 11 0 4 2 18
// out
//      3 17 11 2

// Vector cg nhu 1 kieu du lieu bthg
// Vi the bn co the viet 1 ham co tso la vector hay 1 ham tra ve vector
// Cho 1 vector chua N so nguyen,
// bn hay viet ham tra ve 1 vector chua cac snt trg day so do
// bn phai code tuan thu khuon mau

bool nt(ll n)
{
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
      return false;
  }
  // neu so do ko chia het cho so nao tu 2 -> sqrt(n)
  // thi ktra xem so do co lon hon 1 hay ko : true : > 1, false : < 1
  return n > 1;
}

// ham nay la 1 vector tra ve 1 vector khac chua cac snt ở trg vector v
vector<int> prime_list(vector<int> v) // tham so v chua day so nguyen dau vao
{
  // tao 1 vector ms sau do duyet v, tim so ngto push_back vao
  // tra ve vector ms tao

  // tao ra 1 vector kqua => de luu snt
  vector<int> kq;
  // sau do duyet qua vector v xem thg nao la snt thi push_back vao trg vector kq
  for (int x : v)
  {
    if (nt(x))
    {
      kq.push_back(x);
    }
  }
  return kq;
}
// nhap vao vector => phai tham chieu vao => v= &v
void nhap(vector<int> &v)
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
}
void in(vector<int> v)
{
  for (int x : v)
    cout << x << " ";
}
int main()
{
  vector<int> v;
  nhap(v);
  // trg ham main chi can goi ham prime_list
  // no se tra ve 1 vector chua snt trg vector v
  // sau do gan cho res va duyet res va in ra kqua
  vector<int> res = prime_list(v);
  // vector res=.... : kbao 1 vector res (=toan tu gan, lay kqua tu primelisist(v)
  //=> 1 vector chua cac snt va gan vao res

  // Them : Giam dan, tang dan
  // tang
  sort(res.begin(), res.end());
  sort(res.begin(), res.end(), greater<int>());
  in(res);
  // res se chua cac snt ma prime_list(v) tra ve
}
// B1: viet ham ktra snt
// B2: viet ham tim cac snt trg vector
//  //tra ve 1 vector ms chua cac snt tu vector v,
//  giu thu tu xhien
// B3: viet ham nhap dlieu vao vector
// B4: viet ham in cac ptu cua vector
// main goi ham...

// #include <bits/stdc++.h>
// #include <vector>
// using namespace std;
// using ll = long long;
//
// bool nt(ll n){
//   for (int i = 2; i <= sqrt(n); i++){
//     if (n % i == 0)
//       return false;
//   }
//   return n > 1;
// }
// vector<int> prime_list(vector<int> v)
// {
//   vector<int> kq;
//   for(int x:v){
//     if(nt(x)){
//       kq.push_back(x);
//     }
//   }
//   return kq;
// }
// void nhap(vector<int> &v)
// {
//   int n;
//   cin >> n;
//   for (int i = 0; i < n; i++)
//   {
//     int x;
//     cin >> x;
//     v.push_back(x);
//   }
// }
// void in(vector<int> v)
// {
//   for (int x : v)
//     cout << x << " ";
// }
//
// int main()
// {
//   vector<int> v;
//   nhap(v);
//   vector<int> res = prime_list(v);
//   in(res);
// }