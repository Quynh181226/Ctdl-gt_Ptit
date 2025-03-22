#include <bits/stdc++.h>
using namespace std;
//
// Created by TDG on 22/03/2025.
//
// Nó giống như con trỏ nhưng ko như con trỏ và ko có địa chỉ (con trỏ thông minh)
// Iterator tương tự như con trỏ,
// nó trỏ tới các phần tử trong vector
// và là một kiến thức cực kỳ quan trọng.
// Nó giúp các bạn có thể sử dụng được các hàm,
// thuật toán trong thư viện STL
// Có 4 iterator chính trong vector mà bạn cần nắm được :
// begin() : Iterator trỏ tới phần tử đầu tiên trong vector
// end() : Iterator trỏ tới phần tử sau phần tử cuối cùng trong vector
// rbegin() : Iterator ngược trỏ tới phần tử cuối cùng trong vector
// rend() : Iterator ngược trỏ tới phần tử trước phần tử đầu tiên trong vector
// eg: vector<int> v={1,2,3,4,5}
// Tương tự như con trỏ thì khi bạn muốn truy cập vào phần tử mà iterator
// trong vector đang trỏ tới bạn cần giải tham chiếu bằng toán tử *

// cach khai bao 1 iterator
int main()
{
  vector<int> v = {1, 2, 3, 2, 46, 7, 2};
  //    ::iterator
  //    ::: Toán tử phạm vi (scope resolution operator) trong C++, dùng để truy cập thành phần bên trong một lớp hoặc namespace.
  //    iterator: Đây là một kiểu dữ liệu thành viên (member type) được định nghĩa bên trong lớp vector.
  //    vector<int>::iterator là kiểu iterator dành riêng cho vector<int>.
  //    Iterator hoạt động giống như một con trỏ thông minh, cho phép bạn duyệt qua các phần tử của vector (tăng, giảm, truy cập giá trị, v.v.).
  //    Kết hợp: vector<int>::iterator định nghĩa một iterator dùng để duyệt qua các phần tử kiểu int trong vector.
  //    it
  // it: Đây là tên biến bạn đặt cho iterator. Bạn có thể đặt tên khác tùy ý (ví dụ: iter, pos, v.v.).
  // Sau khi khai báo, it sẽ là một iterator có kiểu vector<int>::iterator, dùng để trỏ đến các phần tử trong v
  //     =
  // Toán tử gán, dùng để gán giá trị cho iterator it.
  // Ở đây, bạn gán giá trị trả về từ v.begin() cho it.
  //     v.begin()
  // v: Là vector mà bạn đang làm việc, kiểu vector<int>.
  // begin(): Là một hàm thành viên của lớp vector, trả về một iterator trỏ đến phần tử đầu tiên của vector.
  // Nếu vector v không rỗng, v.begin() trỏ đến phần tử đầu tiên (ví dụ: v[0]).
  // Nếu vector v rỗng, v.begin() sẽ bằng v.end(), và việc truy cập giá trị tại đó là không hợp lệ.
  // Kiểu trả về: Hàm begin() trả về một iterator có kiểu vector<int>::iterator.
  //     Kết hợp lại:
  // Dòng code vector<int>::iterator it = v.begin();:
  // Khai báo một iterator it có kiểu vector<int>::iterator.
  // Gán cho it giá trị trả về từ v.begin(), tức là trỏ đến phần tử đầu tiên của vector v.
  // vector<int>::iterator it=v.begin();
  // vector<int>::iterator it2=v.end();
  // tro den index thu 3(0123...)
  // vector<int>::iterator it3=v.begin()+3;
  vector<int>::iterator it4 = v.begin() + 1;
  ++it4;
  // muốn bt nó là thằng nào th cout ra nó =  ( dung toan tu giải tham chiếu "*")
  //  cout<<*it<<endl;
  //  cout<<*it2<<endl;
  //  cout<<*it3<<endl;
  // iterator hỗ trợ 4 toán tử để iterator có thể di chuyển trg mảng
  //  ++ -- += -=
  cout << *it4 << endl;

  // duyet qua cac iterator ...
  // or dùng auto .... gan giống vs python
  // cơ mà mấy phần duyệt các kiểu của iterator quá dài dòng nên => bỏ qua

  // END
}