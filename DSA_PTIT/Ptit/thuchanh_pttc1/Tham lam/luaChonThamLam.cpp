//
// Created by TDG on 24/05/2025.
//
#include <bits/stdc++.h>
using namespace std;

string Max(int n, int s) {
    string res(n, '0');
    for (int i = 0; i < n; ++i) {
        res[i] += min(s, 9);
        s -= min(s, 9);
        if (s == 0) break;
    }
    return res;
}

string Min(int n, int s) {
    string res(n, '0');
    res[0] = '1'; s--;
    for (int i = n - 1; i >= 0; --i) {
        res[i] += min(s, 9);
        s -= min(s, 9);
        if (s == 0) break;
    }
    return res;
}

void Solve() {
    int n, s;
    cin >> n >> s;
    if (s <= 0 || s > 9 * n) {
        cout << "-1 -1";
        return;
    }
    cout << Min(n, s) << " " << Max(n, s);
}

main() {
    int t;
    cin >> t;
    while (t--) {
        Solve();
        cout << "\n";
    }
}