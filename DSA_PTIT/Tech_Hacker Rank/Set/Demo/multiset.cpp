#include <bits/stdc++.h>
using namespace std;
//
// Created by TDG on 22/03/2025.
//
//Multiset tương tự như set nhưng có thể lưu nhiều phần tử có giá trị
//giống nhau, các phần tử này cũng được sắp xếp theo thứ tự tăng
//dần. Các hàm của multiset giống y hệt các hàm của set chỉ khác
//một chút ở hàm find, count, erase.

//Hàm find: Vì multiset có thể chứa nhiều phần tử
//giống nhau nên hàm find sẽ trả về iterator đến vị trí
//đầu tiên của phần tử có giá trị cần tìm kiếm.
int find(){
    int a[7] = {5, 5, 1, 1, 2, 2, 2};
    multiset<int> se(a, a + 7);
    //se ={1, 1, 2, 2, 2, 5, 5}
    auto it = se.find(2);
    cout << *it << endl;
    --it;
    cout << *it << endl;
}
//OUTPUT: 2
//        1

int count(){
    int a[7] = {5, 5, 1, 1, 2, 2, 2};
    multiset<int> se(a, a + 7);
    //se ={1, 1, 2, 2, 2, 5, 5}
    cout << se.count(1) << endl;
    cout << se.count(2) << endl;
    cout << se.count(4) << endl;
}
//Hàm count
//
//OUTPUT: 2
//        3
//        0

//Hàm erase: Khi sử dụng hàm erase nếu bạn xóa
//bằng giá trị multiset sẽ xóa hết mọi phần tử có cùng
//giá trị bị xóa, vì thế nếu muốn 1 phần tử bạn phải
//xóa bằng iterator
int erase_value(){
    int a[7] = {5, 5, 1, 1, 2, 2, 2};
    multiset<int> se(a, a + 7);
    //se ={1, 1, 2, 2, 2, 5, 5}
    for(int x : se)
        cout << x << ' ';
    cout << endl;
    se.erase(2);
    for(int x : se)
        cout << x << ' ';
}
//OUTPUT: 1 1 2 2 2 5 5
//        1 1 5 5

int erase_iterator(){
    int a[7] = {5, 5, 1, 1, 2, 2, 2};
    multiset<int> se(a, a + 7);
    //se ={1, 1, 2, 2, 2, 5, 5}
    for(int x : se)
        cout << x << ' ';
    cout << endl;
    auto it = se.find(2);
    se.erase(it);
    for(int x : se)
        cout << x << ' ';
}
//OUTPUT: 1 1 2 2 2 5 5
//        1 1 2 2 5 5
int main(){
  char choice;
    switch (choice) {
        case '1':
            find();
        break;
        case '2':
            count();
        break;
        case '3':
            erase_value();
        break;
        case '4':
            erase_iterator();
        break;
        case '5':
            break;
    }
}