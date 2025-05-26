//
// Created by TDG on 24/05/2025.
//
// Số lộc phát là số chỉ có hai chữ số 6 và 8. Ví dụ 6, 8, 6666, 686886, 88888888 là các số lộc phát. Cho số tự nhiên N không quá 12, hãy liệt kê tất cả các số lộc phát độ dài N theo thứ tự từ nhỏ đến lớn .
// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N.
// T, n thỏa mãn ràng buộc: 1≤T≤10; 1≤N≤12.
// Output:
// Với mỗi test cần đưa ra 2 dòng:
// Dòng đầu ghi ra số lượng số lộc phát tìm được
// Dòng thứ hai ghi lần lượt các số theo thứ tự từ nhỏ đến lớn.
// Ví dụ:
// Input	Output
// 2       	   4
// 2           66 68 86 88
// 3           8
//             666 668 686 688 866 868 886 888

// BFS: Sinh tất cả tổ hợp của 6 và 8, phù hợp khi cần duyệt theo mức (độ dài chuỗi).
// Queue: Đảm bảo thứ tự sinh chuỗi (ngắn trước, dài sau).
// Vector: Lưu trữ linh hoạt, dễ in ngược để đạt thứ tự giảm dần.
// Tính chất bài toán:
// Sinh tổ hợp (combinatorial generation).
// Sắp xếp giảm dần mà không cần so sánh giá trị số (do BFS và in ngược tự động đảm bảo).

// Logic:
// Thuật toán: Sử dụng BFS (Breadth-First Search) với queue để sinh tất cả chuỗi lộc phát độ dài N


// Ý nghĩa:
// queue<string> q;: Tạo một hàng đợi (queue) lưu các chuỗi (string) để sinh số lộc phát. Queue hoạt động theo FIFO (vào trước, ra trước).
// vector<string> v;: Tạo một vector lưu các số lộc phát có độ dài đúng N
// Vai trò:
// Queue dùng để sinh chuỗi theo BFS (chuỗi ngắn hơn xử lý trước).
// Vector lưu kết quả cuối cùng để in.

#include <bits/stdc++.h>
using namespace std;

main() {
    int t; cin >> t;
    if (t < 1 || t > 10) return 1;
    //dùng queue để sinh chuỗi BFS, lưu chuỗi độ dài N vào vector.
    while (t--) {
        int n; cin >> n;
        if (n < 1 || n > 12) continue;
        queue<string> q;
        vector<string> v;
        q.push("6");
        q.push("8");
        //sinh chuỗi = BFS
        while (!q.empty()) {
            string t = q.front(); q.pop();
            if (t.length() == n) {
                v.push_back(t);
                continue;
            }
            q.push(t + "6");
            q.push(t + "8");
        }
        cout << v.size() << endl;
        for (string s : v) {
            cout << s << " ";
        }
        cout << "\n";
    }
}
