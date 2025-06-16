//
// Created by TDG on 20/05/2025.
//

#include<bits/stdc++.h>
using namespace std;

bool search(int a[], int n, int x) {
    for (int i=0;i<n;i++) {
        if (a[i]==x) {
            return true;
        }
    }
    return false;
}
