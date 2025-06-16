//
// Created by TDG on 28/05/2025.
//
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
//để tìm số bước nhỏ nhất từ s đến t
int bfs(int s, int t) {
    //số htai, số bước
    queue<pair<int, int> > q;
    //lưu các số đã thăm, tránh lặp lại.
    unordered_set<int> se;
    // Đẩy cặp {s, 0} vào hàng đợi (bắt đầu từ s, 0 bước).
    // Đánh dấu s là đã thăm bằng cách thêm vào se.
    q.push({s, 0});
    se.insert(s);

    while (!q.empty()) {
        //Mục tiêu là lấy từng trạng thái từ hàng đợi (queue),
        //kiểm tra xem trạng thái đó có phải là số đích t hay không,
        //và nếu không, sinh ra các trạng thái mới (bằng cách nhân đôi
        //hoặc trừ 1) để tiếp tục khám phá.
        pair<int, int> tmp = q.front();
        q.pop();
        int x = tmp.first;
        int step = tmp.second;

        if (x == t) return step;
        if (x * 2 == t || x - 1 == t) return step + 1;

        if (x < t && se.find(x * 2) == se.end()) {
            q.push({x * 2, step + 1});
            se.insert(x * 2);
        }

        if (x >= 1 && se.find(x - 1) == se.end()) {
            q.push({x - 1, step + 1});
            se.insert(x - 1);
        }
    }

    return -1;
}

int main() {
    int s, t;
    cout << "Nhập s và t: ";
    cin >> s >> t;

    int res = bfs(s, t);
    cout << "Số bước nhỏ nhất: " << res << endl;

    return 0;
}

//Lấy số hiện tại và số bước từ hàng đợi.
//Kiểm tra xem số hiện tại có phải là đích hoặc cách đích một bước.
//Nếu không, sinh ra các số mới bằng cách nhân đôi (x * 2) hoặc trừ 1 (x - 1),
//chỉ thêm vào hàng đợi nếu chúng chưa được thăm và thỏa mãn điều kiện.
//Mục tiêu: Tìm số bước nhỏ nhất để đến t bằng cách khám phá tất cả
//các trạng thái có thể theo thứ tự tăng dần số bước.

///////////CHƯA OKE//////////