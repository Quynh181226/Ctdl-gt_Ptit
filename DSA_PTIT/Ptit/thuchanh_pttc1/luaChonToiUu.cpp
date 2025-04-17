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
