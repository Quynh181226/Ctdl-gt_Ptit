//n so fibo dau tien
#include <bits/stdc++.h>
using namespace std;
long long fibo(int n) {
    if (n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}
long long fibo1(int n) {
    if (n<=1) return n;
    //vector<long long> dp(n+1, 0);
    long long dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    //fibo of n
    return dp[n];
}
main() {
    int n; cin >> n;
    cout << fibo(n) << endl;
    cout << fibo1(n) << endl;
}