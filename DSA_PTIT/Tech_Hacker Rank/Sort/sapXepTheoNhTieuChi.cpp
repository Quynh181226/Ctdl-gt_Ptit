// Cho mảng số nguyên A[] có N phần tử, hãy sắp xếp các phần tử trong mảng theo các tiêu trí sau đây:
// Input Format
// Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 là N phần tử trong mảng, các phần tử viết cách nhau một dấu cách. 

// Constraints: (1<=N<=10^5;-10^9<=A[i]<=10^9)

// Output Format
// In ra đáp án của mỗi yêu cầu của bài toán trên 1 dòng.

// Sample Input 0
// 5
// 14 -88 6 23 -14

// Sample Output 0
// 6 14 -14 23 -88 
// 6 -14 14 23 -88 
// -88 -14 14 23 6 
// -88 -14 23 14 6 
// -88 -14 14 6 23 
// 14 6 -14 -88 23 

#include<bits/stdc++.h>
using namespace std;
// #define x int x;
// #define y int y;
// 1.Sắp xếp các phần tử theo giá trị tuyệt đối tăng dần.
bool cmp(int x, int y){
    return abs(x)>abs(y)
}
// 2.Sắp xếp các phần tử theo giá trị tuyệt đối tăng dần.
// Nếu 2 số có cùng giá trị tuyệt đối thì số dương được xếp sau.
bool cmp1(int x, int y){
   if(abs(x)==abs(y)){
    return x > y;
   }
   return abs(x)>abs(y);
}
// 3.Sắp xếp theo tổng chữ số tăng dần.
int tong(int n){
  int sum=0;
}
bool cmp2(int x, int y){

}
// 4.Sắp xếp theo tổng chữ số tăng dần.Nếu 2 số có cùng tổng chữ số thì in ra số có giá trị nhỏ hơn sẽ xếp sau.
// 5.Sắp xếp sao cho các số chẵn xếp trước,các số lẻ xếp sau.
// 6.Sắp xếp sao cho các số chẵn xếp trước theo thứ tự giảm dần,các số lẻ xếp sau theo thứ tự tăng dần.
int main(){

}
