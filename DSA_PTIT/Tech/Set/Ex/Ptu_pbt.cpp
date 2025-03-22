#include<bits/stdc++.h>
using namespace std;
//
// Created by TDG on 22/03/2025.
//
//Bài 1. Phần tử phân biệt
//Cho dãy số A[] gồm có N phần tử, bạn hãy đếm xem trong mảng có bao nhiêu
//phần tử phân biệt? Chú ý giải bài này với 3 cách : Sử dụng set, map, sắp xếp.
//Input Format
//Dòng đầu tiên là số nguyên N. Dòng tiếp theo gồm N số nguyên A[i]
//Constraints
//1≤ N ≤ 10^5; -10^9 ≤ A[i] ≤ 10^9
//Output Format
//In ra số lượng phần tử khác nhau trong mảng.
//Sample Input 0
//5
//2 1 2 1 3
//Sample Output 0
//3
int main() {
  set<int> s={1,3,4,7,9};
  for(set<int>::iterator n=s.begin(); n!=s.end(); n++){
    cout<<*n<<" ";
  }
  cout<<endl;
  //Them dao nguoc ptu rieng bt = reverse_iterator
  for(set<int>::reverse_iterator m=s.rbegin(); m!=s.rend(); m++){
    cout<<*m<<" ";
  }
  cout<<endl;
  //Them dao nguoc ptu rieng bt = auto
  for(auto m=s.rbegin(); m!=s.rend(); m++){
    cout<<*m<<" ";
  }
}