//
// Created by TDG on 22/03/2025.
//
//Bài 2. Truy vấn phần tử trong mảng.
//Cho dãy số A[] gồm có N phần tử, bạn hãy trả lời các truy vấn để xác định xem
//phần tử X nào đó có nằm trong mảng hay không? Bạn hãy thử giải bài này bằng 3
//cách : Set, Map, Binary Search.
//Input Format
// Dòng đầu tiên là số nguyên N.
// Dòng thứ 2 gồm N số nguyên A[i]
// Dòng thứ 3 là số lượng truy vấn Q.
// Q dòng tiếp theo mỗi dòng là một số nguyên X.
//Constraints
//1≤ N ≤ 10^5; 0 ≤ A[i], X ≤ 10^9; 1≤ Q ≤ 1000;
//Output Format
//
//Đối với mỗi truy vấn in ra YES nếu phần tử X xuất hiện trong mảng, ngược lại in
//ra NO.
//Sample Input 0
//5
//1 2 1 3 4
//2
//1
//6
//Sample Output 0
//YES
//NO