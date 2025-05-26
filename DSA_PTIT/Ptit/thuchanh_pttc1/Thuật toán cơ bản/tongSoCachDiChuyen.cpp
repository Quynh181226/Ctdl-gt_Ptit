//
// Created by TDG on 25/05/2025.
//
#include <iostream>
using namespace std;

main() {
    int mod = 1e9 + 7;
    int t;
    cin >> t;
    if (t>100) return 1;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        a[0] = 1;
        a[1] = 1;
        for(int i = 2; i <= n; i++) {
            a[i] = 0;
            for(int j = min(i, k); j >= 1; j--) {
                a[i] += a[i - j] % mod;
                a[i] %= mod;
            }
        }
        cout << a[n] << "\n";
    }
}
