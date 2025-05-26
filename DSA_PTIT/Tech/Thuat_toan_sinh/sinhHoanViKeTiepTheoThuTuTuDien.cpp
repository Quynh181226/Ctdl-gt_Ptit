//
// Created by TDG on 22/05/2025.
//
//hoán vị dãy số
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100];
int b[100];
bool ok;

void sinh() {
    int i = n - 2;
    while(i >= 0 && b[i] > b[i + 1]) {
        i -= 1;
    }
    if(i < 0) ok = false;
    else {
        int j = n - 1;
        while(j > i && b[j] < b[i]) {
            j -= 1;
        }
        swap(b[i], b[j]);
        i += 1;
        j = n - 1;
        while(i < j) {
            swap(b[i], b[j]);
            i += 1;
            j -= 1;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) b[i] = i;
    sort(a, a + n);
    ok = true;
    while(ok) {
        for(int i = 0; i < n; i++) {
            cout << a[b[i]] << " ";
        }
        cout << endl;
        sinh();
    }
    return 0;
}