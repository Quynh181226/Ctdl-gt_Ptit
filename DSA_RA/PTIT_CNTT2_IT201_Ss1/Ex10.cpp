//
// Created by TDG on 16/06/2025.
//
#include<bits/stdc++.h>
using namespace std;
// hVi1: Time O(n), Space O(1)
bool hVi1(string s1, string s2) {
    if (s1.length()!=s2.length()) return false;
    int ascii[256]={0};
    for (char c : s1) ascii[c]++;
    for (int i=0; i<s2.length(); i++) ascii[s2[i]]--;
    for (int i=0; i<256; i++) {
        if (ascii[i]) return false;
    }
    return true;
}

// hVi2: Time O(n log n), Space O(n)
bool hVi2(string s1, string s2) {
    if (s1.length()!=s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1==s2;
}

main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << (hVi1(s1, s2)?"true":"false") << endl;
    cout << (hVi2(s1, s2)?"true":"false") << endl;
}