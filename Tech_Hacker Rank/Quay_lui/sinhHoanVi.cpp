//
// Created by TDG on 22/05/2025.
//
#include <iostream>
#include <cstring>

using namespace std;

int a[100];
int n;
bool used[100];

void quayLui(int i) {
    for(int j = 1; j <= n; j++) {
        if(!used[j]) {
            a[i] = j;
            used[j] = true;
            if(i == n - 1) {
                for(int idx = 0; idx < n; idx++) {
                    cout << a[idx];
                }
                cout << " ";
            }
            else quayLui(i + 1);
            used[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        memset(used, false, sizeof(used));
        quayLui(0);
        cout << endl;
    }
    return 0;
}
