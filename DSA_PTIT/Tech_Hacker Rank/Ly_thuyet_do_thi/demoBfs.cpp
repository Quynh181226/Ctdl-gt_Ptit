//
// Created by TDG on 07/07/2025.
//
//bfs có chức năng lưu đỉnh gần vs đỉnh hiện tại hơn
//bfs không giống như dfs phải dùng dệ quy mà cứ xem đỉnh nào gần hơn thì thăm trc
#include <bits/stdc++.h>
using namespace std;
//0 ở đây đang biểu thị là rỗng
int bfs(u) {
    //Step 1: Khởi tạo
    //tạo 1 hàng đợi rỗng
    queue=0;
    //đẩy đỉnh u vào hàng đợi
    push(queue, u);
    //đánh dấu đỉnh u đã được thêm
    //Step 2: Lập khi mà hàng đợi vẫn còn phần tử
    while (queue!=0) {
        //lấy ra đỉnh ở đầu hàng đợi
        v.queue.front();
        //xóa đỉnh khỏi đầu hàng đợi
        queue.pop();
        //thăm đỉnh
        //duyệt các đỉnh kề với v mà chưa được thăm và đẩy vào hàng đợi
        for (int x: ke[v]) {
            //nếu x chưa được thăm
            if (!visited[x]) {
                push(queue, x);
                visited[x] = true;
            }
        }
    }
}