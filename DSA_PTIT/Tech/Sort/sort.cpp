#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
using ll=long long;
//sort: array, vector, string
//sort(start,end);
//start: vị trí bắt đầu (con trỏ hoặc iterator)
//end: vị trí sau phần tử cuối cùng (not inclusive) => sort sẽ sắp xếp từ start đến end - 1

//Sắp xếp toàn bộ mảng a có n phần tử
sort(a, a + n);
//Sắp xếp mảng a từ chỉ số x tới chỉ số y
sort(a + x, a + y + 1);
//Sắp xếp mảng giảm dần
sort(a, a + n, greater<data_type>());
//Sắp xếp toàn bộ vector a có n phần tử
sort(a.begin(), a.end());
//Sắp xếp vector a từ chỉ số x tới chỉ số y
sort(a.begin() + x, a.begin() + y + 1);
//Sắp xếp vector giảm dần
sort(a.begin(), a.end(), greater<data_type>());
//a+i: con tro tro den thang a[i]
//sort(a, a+n)
//Sxep toan bo mang a tu a[0]->a[n-1]

//sort(a+x,a+y+1)
//Sxep 1 doan con cua mang a tu chi so x->y
//eg: sort(a+2, a+5);
//Sxeo tu a[2]->a[4](vi end ko bao gom)

//sort(v.begin(), v.end())
//Sxep toan bo vector theo thu tu tang dan

//sort(v.begin()+x, v.begin()+y+1)
//Sxep 1 doan con cua vector v tu chi so x -> y
//eg: vector<int> v = {4, 1, 3, 5, 2};
// sort(v.begin() + 1, v.begin() + 3);
// sắp xếp từ phần tử thứ 1 đến 3-1 = 2 => tức là v[1], v[2]

int main(){
    int a[] = {3, 1, 2, 1, 2, 6, 7, 9, 10, 8};
    int n = 10;
    //day la sort kieu tthg, mdinh
    sort(a, a + n);
    //con day la sort theo ttu giam dan 
    sort(a, a+n, greater<int>());
    for(int x : a) cout << x << " ";
}