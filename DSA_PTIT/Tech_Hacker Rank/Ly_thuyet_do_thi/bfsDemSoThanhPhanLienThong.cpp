//
// Created by TDG on 06/07/2025.
//
// [Graph]. Bài 13. Đếm số thành phần liên thông
// Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy
// đếm số thành phần liên thông của đồ thị.
// Input Format
// Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các
// đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v
// (u != v) tương ứng với một cạnh của đồ thị.
// Constraints
// 1<=n<=1000; 1<=m<=n*(n-1)/2;
// Output Format
// In ra số thành phần liên thông của đồ thị
// Sample Input 0
// 5 4
// 4 1
// 2 1
// 3 2
// 4 3
// Sample Output 0
// 2
// Sample Input 1
// 5 2
// 4 1
// 2 1
// Sample Output 1
// 3