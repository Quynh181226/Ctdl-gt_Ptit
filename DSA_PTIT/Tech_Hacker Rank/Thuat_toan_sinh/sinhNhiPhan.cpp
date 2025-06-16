//
// Created by TDG on 22/05/2025.
//
#include <iostream>

using namespace std;

int a[100];
int n;
bool ok;

bool check() {
    int l = 0, r = n - 1;
    while(l < r) {
        if(a[l] != a[r]) return false;
        l += 1;
        r -= 1;
    }
    return true;
}

void sinh() {
    int i = n - 1;
    while(i >= 0 && a[i] == 1) {
        a[i] = 0;
        i -= 1;
    }
    if(i < 0) ok = false;
    else {
        a[i] = 1;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) a[i] = 0;
    ok = true;
    while(ok) {
        if(check()) {
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        }
        sinh();
    }
    return 0;
}