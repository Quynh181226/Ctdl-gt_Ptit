- HEXGAME

HEXGAME là một trò chơi xếp hình gồm 10 miếng ghép hình lục giác đều,
trên mỗi miếng ghép được điền một số nguyên, có 8 miếng được điền số từ 1 đến 8
và có hai miếng điền số 0. Các miếng liên kết với nhau tạo thành lưới tổ ong.
Ban đầu các miếng ghép ở vị trí như hình vẽ. Tại mỗi bước, chọn một miếng ghép
có đúng 6 miếng ghép kề cạnh làm tâm, rồi xoay một nấc 6 miếng ghép kề cạnh đó
theo chiều kim đồng hồ. Như vậy chỉ có hai cách chọn tâm, đó là chọn tâm bên trái
và chọn tâm bên phải.

![img.png](img.png)
Yêu cầu: Cho một trạng thái của trò chơi (nhận được sau một dãy biến đổi từ trạng thái
ban đầu), hãy tính số phép biến đổi ít nhất để đưa về trạng thái ban đầu.

Input:

Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm:
Dòng đầu tiên chứa 3 số ở 3 miếng ghép dòng thứ nhất (thứ tự từ trái qua phải).
Dòng thứ hai chứa 4 số ở 4 miếng ghép dòng thứ hai (thứ tự từ trái qua phải).
Dòng thứ 3 chứa 3 số ở 3 miếng ghép dòng thứ ba (thứ tự từ trái qua phải).

Output:

Với mỗi bộ test in ra một số nguyên là số phép biến đổi ít nhất để đưa được về trạng thái ban đầu.
Ví dụ:

Input	                    Output
1 1 0 2 8 6 0 3 7 5 4	    5
