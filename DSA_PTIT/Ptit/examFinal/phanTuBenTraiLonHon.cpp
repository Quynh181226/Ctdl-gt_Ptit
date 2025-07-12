//
// Created by TDG on 12/07/2025.
//
// DSA07027 - PHẦN TỬ BÊN TRÁI ĐẦU TIÊN LỚN HƠN
// Cho dãy số nguyên A[] gồm N phần tử. Với mỗi phần tử A[i], hãy tìm phần tử đầu tiên ở bên trái nó (tức là phần tử có chỉ số nhỏ hơn i) mà lớn hơn A[i].
// Nếu không có phần tử nào như vậy thì in ra -1.
//
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
//
// Mỗi test gồm:
//
// Một số nguyên N (1 ≤ N ≤ 100000) — số phần tử trong mảng.
//
// Một dòng gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).
//
// Output:
// Với mỗi test, in ra trên một dòng N số R[i], với R[i] là phần tử đầu tiên bên trái lớn hơn A[i], hoặc -1 nếu không có.
//
// Ví dụ:
// Input:
// 1
// 6
// 2 5 1 3 4 2
// Output:
// -1 -1 5 5 5 4