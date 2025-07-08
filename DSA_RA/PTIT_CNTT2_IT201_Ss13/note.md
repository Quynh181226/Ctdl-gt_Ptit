+ **strdup**() : là 1 hàm, cú pháp const char *x or char *x 
- Cấp phát vùng nhớ mới và lưu bản sao của chuỗi x vào stack
- “Copy” trong strcpy() là sao chép từ mảng (kí tự) có sẵn và dán sang mảng có sẵn khác. Kích thước có thể không giống nhau.

“Duplicate” trong strdup() là nhân bản từ mảng có sẵn thành một mảng mới khác vùng nhớ với mảng ban đầu. Cùng kích thước.

Copy: mình bắt chước bạn.
Duplicate: nhân bản vô tính của bạn. Clone!
+ **isalnum**() -> isalnum(int c)
- hàm void kiểm tra xem ký tự đã truyền có phải là ký tự - số hay ko 
- có trả về  giá trị # 0
- ko trả về 0
+ **sprintf**() : là 1 hàm int sprintf(char *str, const char format)
- str : con trỏ tới một mảng các phần tử char nơi chuỗi kết quả được lưu trữ
- format : chuỗi chứa text để được ghi tới buffer. 
         có thể tùy ý chứa các thẻ định dạng có thể được nhúng  mà được thay thế bởi
         các giá trị được xác định trong các tham số bổ sung tiếp theo và được định dạng theo yêu cầu.
+  Vì sao cần char** trong stack?
   Bạn đang xây stack để lưu các biểu thức chuỗi như (a+b), (a+(b*c)),...

Nên:

Thành phần      	            Kiểu dữ liệu
Một chuỗi	                    char*
Stack các chuỗi	                char**
Stack có data lưu các chuỗi 	char** data

+ precedence : là 1 hàm tự định nghĩa trả về độ ưu tiên, xác định độ ưu tiên của toán tử