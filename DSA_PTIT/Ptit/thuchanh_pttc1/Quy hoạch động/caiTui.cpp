//DSA05027 - CÁI TÚI
//Một người có cái túi thể tích V (V<1000). Anh ta có N đồ vật cần mang theo (N≤1000), mỗi đồ vật có thể tích là A[i] (A[i]≤100) và giá trị là C[i] (C[i]≤100). Hãy xác định tổng giá trị lớn nhất của các đồ vật mà người đó có thể mang theo, sao cho tổng thể tích không vượt quá V.
//Input
//Dòng đầu ghi số bộ test T (T<10)
//Mỗi bộ test gồm ba dòng. Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng A. Sau đó là một dòng ghi N số của mảng C.
//Dữ liệu vào luôn đảm bảo không có đồ vật nào có thể tích lớn hơn V.
//Output
//Với mỗi bộ test, ghi trên một dòng giá trị lớn nhất có thể đạt được.
//Ví dụ
//Input	Output
//1 15 10 5 2 1 3 5 2 5 8 9 6 3 1 4 7 8 1 2 3 5 1 2 5 8 7 4 1 2 3 2 1	15
#include<bits/stdc++.h>
using namespace std;
int F[1001][1001], N, M, A[1001], C[1001];
int qhd(){
    int i,j;
    memset(F,0,sizeof(F));
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            F[i][j] = F[i-1][j];
            if(j >= A[i]){
                F[i][j] = max(F[i][j], F[i-1][j-A[i]] + C[i]);
            }
        }
    }
    return F[N][M];
}
main(){
    int t, i;
    cin >> t;
    while(t--){
        cin >> N >> M;
        for(i=1;i<=N;i++) cin >> A[i];
        for(i=1;i<=N;i++) cin >> C[i];
        cout << qhd() << endl;
    }
}