#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//
// Created by TDG on 20/05/2025.
//
//Xâu nhị phân có độ dài N: x1, x2,...., xn

/////Sinh khác với quay lui vét cạn ntn?
///x[]={x1, x2, x3, ..., xn}
///sinh thì ta phải có toàn bộ cấu hình này rồi từ cấu hình đó sinh ra cấu hình kế tiếp
///quay lui thì thử x1 có thể nhận đc nhg gtri nào sau đó nó sẽ chẽ ra lời gọi đệ quy cho phép thử tương ứng đó
///và sau khi gán x1 xg nó sẽ gọi đệ quy lên x2 tiếp ....
///giống quy tắc nhân gọi đến xn thì ms in ra cấu hình

///1. Thử tất cả khả năng cho một vị trí.
///2. Gọi đệ quy để xử lý vị trí tiếp theo.
///3. Quay lại để thử khả năng khác khi cần.

int n, x[100];

void inKq() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}

void Try(int i) {
    //Duyet cac knang cua x[i]
    for (int j = 0; j <= 1; j++) {
        //Gan x[i]= knang thu j đó
        x[i] = j;
        //Va ktra neu da xdung den cai bit cuoi cung roi thi in ra kqua
        if (i == n) {
            inKq();
        } else {
            Try(i + 1);
        }
    }
}

//sinh xâu nhị phân
int x1[100], n1;
void Try1(int i) {
    for (int j = 0; j <= 1; j++) {
        x1[i] = j;
        if (i == n1) {
            for (int k = 1; k <= n1; k++) {
                cout << x1[k] << " ";
            }
            cout << endl;
        } else {
            Try1(i + 1);
        }
    }
}

//sinh tổ hợp chập k của n
int x2[100], n2, k;
void in() {
    for (int i = 1; i <= k; i++) {
        cout << x2[i] << " ";
    }
    cout << endl;
}
void Try2(int i) {
    for (int j = x2[i - 1] + 1; j <= n2 - k + i; j++) {
        x2[i] = j;
        if (i == k) {
            in();
        } else {
            Try2(i + 1);
        }
    }
}

//sinh hoán vị
int x3[100], n3, used[100];
void Try3(int i) {
    for (int j = 1; j <= n3; j++) {
        if (used[j] == 0) {
            x3[i] = j;
            used[j] = 1;
            if (i == n3) {
                for (int z = 1; z <= n3; z++) {
                    cout << x3[z] << " ";
                }
                cout << endl;
            } else {
                Try3(i + 1);
            }
            used[j] = 0;
        }
    }
}

//In ra cau hinh nhi phan nguoc x[n] x[n-1] ... x[1]
int x4[100], n4;
void inKq4() {
    for (int i = n4; i >= 1; i--) {
        cout << x4[i];
    }
    cout << endl;
}
void Try4(int i) {
    for (int j = 0; j <= 1; j++) {
        x4[i] = j;
        if (i == n4) {
            inKq4();
        } else {
            Try4(i + 1);
        }
    }
}

int main() {
    cin >> n;
    Try(1);

    cin >> n1;
    Try1(1);

    cin >> n2 >> k;
    x2[0] = 0;
    Try2(1);

    cin >> n3;
    Try3(1);

    cin >> n4;
    Try4(1);

    return 0;
}
