//
// Created by TDG on 28/06/2025.
//
Hint
Với giới hạn lên tới 10^6, việc duyệt qua từng số rồi tìm ước nguyên tố lớn nhất là không thể, vì ta sẽ mất O(n−−√)
để tìm ước, tức là xấp xỉ 10^3→tổng độ phức tạp sẽ là O(10^9), vượt quá 1giây cho phép.
Để có thể tối ưu được thời gian, ta sẽ cần sử dụng Sàng Biến Đổi ở đây. Đầu tiên, ta sẽ duyệt qua các số trong đoạn [2,106], với mỗi số i
đang xét tới, ta sẽ duyệt các bội của nó và cập nhật ước nguyên tố lớn nhất hiện tại chính là i. Tiếp theo, các truy vấn tính tổng tĩnh trong
đoạn [l,r] nào đó, ta sẽ phải nghĩ ngay đến Tổng cộng dồn để tiếp tục tối ưu thời gian, chứ không thể duyệt trâu các truy vấn được.
#include<bits/stdc++.h>
using namespace std;
//lưu ước nguyên tố lớn nhất của số i
int a[1000001];
long long b[1000001];
void pre(int n){
f
// nếu chưa có ước số nguyên tố nhỏ nhất (có nghĩa i là số nguyên tố)
i
f
// đánh dấu i là ước số nguyên tố nhỏ nhất của j
a
}
int main(){
cin.tie(0)->sync_with_stdio(0);
}
//=> Đây là một biến thể của thuật toán sàng Eratosthenes, nhưng thay vì đánh dấu số nguyên tố, ta đánh dấu ước số nguyên tố nhỏ nhất.