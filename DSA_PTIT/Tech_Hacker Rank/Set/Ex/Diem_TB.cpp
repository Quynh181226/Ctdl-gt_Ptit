//
// Created by TDG on 22/03/2025.
//
//Bài 37. Điểm trung bình
//Cho thông tin điểm thi của các môn học của các sinh viên, bạn hãy tính điểm
//trung bình của sinh viên đó và in ra màn hình. Điểm trung bình được tính bằng
//cách lấy tổng hệ số điểm và số tín chỉ chia cho tổng số tín chỉ. Ví dụ sinh viên X
//học môn A 2 tín chỉ và có điểm là 5, môn B 3 tín chỉ và có điểm là 4 thì điểm
//trung bình được tính = (2 * 5 + 3 * 4) / (2 + 3).
//Input Format
// Gồm nhiều dòng, mỗi dòng gồm 3 thông tin : Tên sinh viên (có 1 từ), số tín
//chỉ và điểm số tương ứng. Dữ liệu đảm bảo không có 2 sinh viên có cùng
//tên.
//Constraints
// Điểm là số nguyên từ 0 tới 10, số tín chỉ là số nguyên dương
//Output Format
// In ra danh sách sinh viên theo thứ tự từ điển giảm dần và điểm trung bình
//lấy 2 số sau dấu phẩy.
//Sample Input 0
//Lan 4 8
//
//Hanh 4 5
//Lan 6 10
//Phong 4 10
//Nam 4 9
//Phong 6 5
//Lan 2 4
//Phuong 6 1
//Nhung 2 7
//Nhung 6 9
//Nhung 5 8
//Nhung 4 10
//Lan 3 1
//Sample Output 0
//Phuong : 1.00
//Phong : 7.00
//Nhung : 8.71
//Nam : 9.00
//Lan : 6.87
//Hanh : 5.00
//Sample Input 1
//Nhung 5 1
//Phong 2 6
//Ngoc 5 8
//Phuong 3 10
//Ngoc 3 4
//Nhung 2 10
//Ngoc 3 3
//Nam 5 1
//Nhung 3 5
//Ngoc 4 7
//Lan 3 5
//Phong 5 2
//Phuong 6 3
//Nhung 4 1
//Nhung 4 5
//Sample Output 1
//Phuong : 5.33
//Phong : 3.14
//Nhung : 3.56
//Ngoc : 5.93
//Nam : 1.00
//Lan : 5.00