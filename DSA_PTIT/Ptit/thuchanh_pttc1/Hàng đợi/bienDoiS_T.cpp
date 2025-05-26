// #include <bits/stdc++.h>
using namespace std;

int biendoi(int s, int t) {
    int a[20001] = {0};
    queue<int> q;
    q.push(s);
    a[s] = 0; 

    while (a[t] == 0 && !q.empty()) { 
        int x = q.front(); q.pop();
        if (x - 1 > 0 && a[x - 1] == 0) {
            a[x - 1] = a[x] + 1;
            q.push(x - 1);
        }
        if (x * 2 < 20000 && a[x * 2] == 0) {
            a[x * 2] = a[x] + 1;
            q.push(x * 2);
        }
    }
    return a[t];  
}

main() {
    int test, s, t;
    cin >> test;
    while (test--) {
        cin >> s >> t;
        cout << biendoi(s, t) << endl;
    }
}
