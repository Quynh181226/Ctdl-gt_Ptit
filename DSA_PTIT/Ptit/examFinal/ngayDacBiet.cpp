//
// Created by TDG on 09/07/2025.
//
// DSA02022 - NGÀY ĐẶC BIỆT
// Hôm nay là ngày 22/02/2022. Một ngày đặc biệt. Chỉ có hai chữ số là 0 và 2. Đồng thời viết xuôi viết ngược tám chữ số ta đều được cùng một kết quả.
//
// Nhiệm vụ của bạn trong ngày đặc biệt này là hãy liệt kê hết tất cả các ngày hợp lệ chỉ có 2 chữ số 0 và 2.
//
// Một số chú ý:
//
// Luôn có đủ 8 chữ số của ngảy tháng năm và hai dấu gạch chéo.
// Ngày và tháng có thể có chữ số 0 ở đầu nhưng với năm thì không được phép. Tức là ta chỉ tính các ngày bắt đầu từ năm 2000 trở về sau.
// Bài toán không có dữ liệu vào. Bạn chỉ cần liệt kê kết quả gồm tất cả các ngày tháng hợp lệ. Coi dãy ký tự ngày tháng là một xâu ký tự. Hãy liệt kê theo đúng thứ tự từ điển tăng dần.
#include <iostream>

using namespace std;

int a[8];

bool check() {
    if(a[0] == 0 && a[1] == 0) return false;
    if(a[2] == 2 || a[3] == 0) return false;
    if(a[4] == 0) return false;
    return true;
}

void quayLui(int i) {
    for(int j = 0; j <= 2; j += 2) {
        a[i] = j;
        if(i == 7) {
            if(check()) {
                cout << a[0] << a[1] << "/" << a[2] << a[3] << "/" << a[4] << a[5] << a[6] << a[7] << endl;
            }
        }
        else quayLui(i + 1);
    }
}
int main() {
    quayLui(0);
    return 0;
}
