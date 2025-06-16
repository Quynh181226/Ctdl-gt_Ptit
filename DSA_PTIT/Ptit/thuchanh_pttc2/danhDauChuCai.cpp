//
// Created by TDG on 12/06/2025.
//
#include<bits/stdc++.h>
using namespace std;

// main() {
//     string s;
//     getline(cin, s);
//     int a[127]={0};
//     //dem so lan xuat hien cua ki tu
//     for (char c: s) {
//         a[c]++;
//     }
//     int res=0;
//     //dem so ktu khac nhau
//     for (char c='a'; c<='z'; c++) {
//         if (a[c]>0) {
//             res++;
//         }
//     }
//     cout << res << '\n';
// }
main() {
    string s;
    getline(cin, s);
    set<char> st;
    for (char c: s) {
        c=tolower(c);
        //or la isalpha
        if (c>='a' && c<='z') {
            st.insert(c);
        }
    }
    cout<<st.size()<<'\n';
}
