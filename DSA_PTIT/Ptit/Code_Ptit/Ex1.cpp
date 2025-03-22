#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        // Nhập và kiểm tra (nếu cần)
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            // if (a[i] < 1000 || a[i] > 9999) {
            //     cout << "Invalid number: must have exactly 4 digits" << endl;
            //     return 1;
            // }
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}