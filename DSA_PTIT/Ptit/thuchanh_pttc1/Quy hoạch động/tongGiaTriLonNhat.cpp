//Một tên trộm đột nhập vào một cửa hiệu tìm thấy n món hàng có trọng lượng và giá trị khác nhau,
//nhưng hắn chỉ mang theo một cái túi có sức chứa về trọng lượng tối đa là M. Vậy tên trộm nên bỏ
//vào túi những món nào để đạt giá trị cao nhất trong khả năng mà hắn có thể mang đi được.
//Input
//Dòng đầu tiên chứa hai số nguyên dương n và M (1 ≤ n, M ≤ 5000).
//n dòng tiếp theo, mỗi dòng chứa hai số nguyên dương x và y mô tả một đồ vật có trọng lượng x
//và giá trị y (1 ≤ x ≤ M, 1 ≤ y ≤ 10000).
//Output
//In ra tổng giá trị lớn nhất đạt được.
// Input
// 10 50
// 33 6
// 19 3
// 12 8
// 22 7
// 18 3
// 34 10
// 14 10
// 21 9
// 26 10
// 40 4
// Output
// 27

#include <bits/stdc++.h>
using namespace std;

int F[5001][5001], N, M, A[5001], C[5001];

int qhd(){
    int i, j;
    memset(F, 0, sizeof(F));
    for(i = 1; i <= N; i++){
        for(j = 1; j <= M; j++){
            F[i][j] = F[i - 1][j];
            if(j >= A[i]){
                F[i][j] = max(F[i][j], F[i - 1][j - A[i]] + C[i]);
            }
        }
    }
    return F[N][M];
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> A[i] >> C[i];
    }
    cout << qhd() << endl;
    return 0;
}
