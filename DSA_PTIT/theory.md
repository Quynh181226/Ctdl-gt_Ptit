                      =====THEORY=====
**Quy hoạch động**, **Ngăn xếp (Stack)**, và **Hàng đợi (Queue)**.....:

| Thuật toán / Cấu trúc                    | Định nghĩa ngắn                                               | Đặc điểm chính                              | Ứng dụng chính                                |
| ---------------------------------------- | ------------------------------------------------------------- | ------------------------------------------- | --------------------------------------------- |
| **Sinh (Generation)**                    | Tạo tất cả cấu hình thỏa điều kiện                            | Liệt kê toàn bộ, theo thứ tự xác định       | Sinh dãy nhị phân, tổ hợp, hoán vị            |
| **Đệ quy (Recursion)**                   | Hàm gọi lại chính nó để giải bài toán con                     | Giải quyết bài toán theo cấu trúc phân cấp  | Kết hợp với sinh, quay lui                    |
| **Quay lui (Backtracking)**              | Thử tất cả lựa chọn, quay lui khi không hợp lệ                | Duyệt không gian lời giải, có thể cắt nhánh | Tìm lời giải hợp lệ, bài toán tổ hợp          |
| **Quay lui vét cạn**                     | Quay lui thử tất cả trường hợp, không cắt nhánh               | Thời gian lớn, liệt kê toàn bộ không gian   | Bài toán nhỏ, khi không có tối ưu             |
| **Nhánh cận (Branch and Bound)**         | Cắt bỏ nhánh không tốt hơn lời giải hiện tại                  | Giảm số trường hợp thử, tối ưu hơn quay lui | Bài toán tối ưu tổ hợp                        |
| **Tham lam (Greedy)**                    | Chọn bước tốt nhất tại mỗi thời điểm                          | Nhanh, đơn giản, không phải lúc nào đúng    | Bài toán tối ưu có tính chất tham lam         |
| **Quy hoạch động (Dynamic Programming)** | Giải bài toán bằng cách lưu lại kết quả con để tránh tính lại | Tối ưu theo bước, giảm thời gian tính       | Bài toán tối ưu, đếm, bài toán con chồng chéo |
| **Ngăn xếp (Stack)**                     | Cấu trúc dữ liệu LIFO (Last In First Out)                     | Thao tác push/pop nhanh, theo thứ tự ngược  | Undo, duyệt cây, giải thuật biểu thức         |
| **Hàng đợi (Queue)**                     | Cấu trúc dữ liệu FIFO (First In First Out)                    | Thao tác enqueue/dequeue theo thứ tự đến    | BFS, quản lý tác vụ, mô phỏng hàng chờ        |

| Thuật toán / Cấu trúc | Định nghĩa ngắn         | Đặc điểm chính                            | Trả giá trị |
| --------------------- | ----------------------- |-------------------------------------------|-------------|
| **pop_back()**        | vector, deque, string   | Xóa phần tử cuối cùngổ hợp, hoán vị       | Ko          |
| **erase()**           | vector, list, map, ...  | Xóa theo vị trí hoặc phạm vi              | Ko          |
| **pop()**             | stack, queue            | Xóa phần tử đầu (queue) hoặc cuối (stack) | Ko          |

### `Memset`

**`memset`** là một hàm trong C/C++ (có trong thư viện `<cstring>`) dùng để gán một giá trị cụ thể cho một khối bộ nhớ liên tiếp.

#### Cú pháp
```cpp
void *memset(void *ptr, int value, size_t num);
```
- `ptr`: Con trỏ đến khối bộ nhớ cần gán giá trị.
- `value`: Giá trị cần gán (thường là 0 hoặc -1, được hiểu là byte).
- `num`: Số byte cần gán giá trị.

#### Cách hoạt động
- Gán giá trị `value` cho `num` byte liên tiếp bắt đầu từ địa chỉ `ptr`.
- `value` được áp dụng dưới dạng byte, nên thường dùng để đặt giá trị 0 (cho false, null) hoặc -1.

#### Sử dụng trong code
```cpp
memset(used, false, sizeof(used));
```
- Đặt tất cả phần tử của mảng `used` (kiểu `bool`) về `false` (0).
- `sizeof(used)` tính kích thước mảng `used` (100 * sizeof(bool)).
- Dùng để khởi tạo mảng `used` trước mỗi test case, đảm bảo không có số nào được đánh dấu là đã dùng.

#### Khi nào dùng
- **Khởi tạo mảng hoặc cấu trúc**: Dùng để đặt giá trị ban đầu (thường là 0 hoặc -1) cho mảng lớn hoặc cấu trúc, nhanh hơn vòng lặp.
- **Tiết kiệm thời gian**: Hiệu quả hơn so với vòng lặp khi khởi tạo khối bộ nhớ lớn.
- **Ví dụ khác**:
  - Đặt mảng số về 0: `memset(arr, 0, sizeof(arr));`
  - Đặt mảng ký tự về null: `memset(str, '\0', sizeof(str));`

#### Lưu ý
- Chỉ nên dùng với giá trị 0 hoặc -1, vì `memset` gán giá trị theo byte, không phù hợp với các giá trị khác (ví dụ: gán 5 sẽ sai).
- Kiểm tra kích thước mảng cẩn thận để tránh truy cập ngoài bộ nhớ.




`- ws là một manipulator (được định nghĩa trong <iomanip>, 
nhưng <bits/stdc++.h> đã bao gồm nó) có tác dụng bỏ qua các ký tự trắng (whitespace)
như khoảng cách, tab, hoặc ký tự xuống dòng (\n) trong bộ đệm của cin`

                  --BFS--
- Là thuật toán duyệt or tkiem trg đồ thị or cây,
- đi theo tầng nghĩa là duyệt tất cả các đỉnh kề trước,
- để duyệt tất cả tổ hợp.
- khi đi sâu hơn(duyệt theo mức level eg: độ dài chuỗi)

                  - - -Cách hoạt động của BFS: - - -
1. Bắt đầu từ một đỉnh nguồn.
2. Dùng hàng đợi (queue) để lưu các đỉnh đang chờ duyệt.
3. Duyệt từng đỉnh từ hàng đợi → lấy ra → duyệt các đỉnh kề chưa thăm → đưa vào hàng đợi.
- Mã giả (pseudocode):


  BFS(u):

 `````đánh dấu u đã thăm

   queue.push(u)

   while queue không rỗng:

       v = queue.pop()

       xử lý đỉnh v

       for tất cả đỉnh kề w của v:

          nếu w chưa thăm:

             đánh dấu w đã thăm

             queue.push(w)