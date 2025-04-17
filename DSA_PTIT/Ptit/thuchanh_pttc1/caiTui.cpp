#include <bits/stdc++.h>
using namespace std;

int F[5001][5001], N, M, A[1001], C[1001];

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
