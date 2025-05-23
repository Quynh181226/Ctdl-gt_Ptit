//
// Created by TDG on 22/03/2025.
//
//Bài 16. Tìm kiếm sinh viên.
//Ở trường đại học xyz, mỗi sinh viên sẽ có một mã sinh viên riêng. Mã sinh viên là
//một xâu kí tự không quá 8 kí tự. Bạn được yêu cầu xây dựng chương trình có thể
//kiểm tra một mã sinh viên nào đó có thuộc về sinh viên nào?
////Gợi ý dùng map<string, string> mp;
////Trong đó key thì lưu mã sinh viên và value thì lưu tên
//Input Format
// Dòng đầu tiên là số lượng sinh viên N.
// 2N dòng tiếp theo là các dòng tiếp theo mô tả thông tin của sinh viên trên
//2 dòng, dòng đầu là mã sinh viên, dòng 2 là tên sinh viên.
// Dòng tiếp theo là số truy vấn Q.
// Q dòng tiếp theo, mỗi dòng là một mã sinh viên cần tìm kiếm, nếu mã sinh
//viên này thuộc về một bạn sinh viên thì in ra tên của sinh viên đó trên 1
//dòng, ngược lại in ra "NOT FOUND" trên 1 dòng.
//Constraints
// 1≤ N ≤ 10^4; 1≤ Q ≤ 1000
// Mã sinh viên là xâu kí tự không quá 8 kí tự
// Tên sinh viên là một xâu có không quá 30 kí tự
//Output Format
//In ra kết quả của từng truy vấn, mỗi truy vấn trên 1 dòng.
//Sample Input 0
//3
//SV001
//Hoang Van Nam
//SV002
//Ngo Gia Long
//SV005
//
//Phuong The Ngoc
//2
//SV005
//SV003
//Sample Output 0
//Phuong The Ngoc
//NOT FOUND