// Trên trục Ox tính từ vị trí 0, người ta muốn xếp nhiều nhất các đoạn thẳng sao cho không đoạn nào chồng lấn lên nhau.
// Đoạn thẳng thứ i có vị trí bắt đầu là X1[i] và kết thúc tại X2[i], với X1[i] <= X2[i].
// Hãy tính số đoạn thẳng nhiều nhất có thể được lựa chọn để đưa lên trục Ox và không có đoạn nào chồng lấn lên nhau.
// Input
// Dòng đầu tiên ghi số bộ test, không quá 10.
// Với mỗi bộ test: dòng đầu ghi số N là số đoạn thẳng (không quá 105)
// Tiếp theo là N dòng, mỗi dòng có 2 số nguyên mô tả đoạn thẳng. Các giá trị tọa độ đều là các số nguyên không âm và không quá 106.
// Output
// Với mỗi test, viết trên 1 dòng số lượng đoạn thẳng nhiều nhất có thể được lựa chọn thỏa mãn điều kiện đề bài.
// Input
// 1
// 10
// 39 55
// 37 74
// 0 1
// 19 25
// 65 76
// 51 52
// 19 21
// 5 94
// 46 65
// 32 40
// Output
// 5
#include <bits/stdc++.h>
using namespace std;

struct task {
    int start, finish;
};

bool cmp(task x, task y) {
    return x.finish < y.finish;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<task> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i].start >> a[i].finish;

        sort(a.begin(), a.end(), cmp);

        int l = -1, d = 0;
        for (int j = 0; j < n; j++) {
            if (a[j].start >= l) {
                d++;
                l = a[j].finish;
            }
        }
        cout << d << endl;
    }
    return 0;
}
