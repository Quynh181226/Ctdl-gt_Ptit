//
// Created by TDG on 24/06/2025.
//
//
#include <bits/stdc++.h>
using namespace std;
void slove() {
int k; cin >> k;
    string s; cin >> s;
    int a[127]={};
    for (int i = 0; i < s.length(); i++) a[i]++;
    priority_queue<int> q;
    //dua cac tan suat > 0 vao prior
    //duyet qua tung ptu trg a
    //neu tan suat i>0((ky tu ton tai trg xau)" con=0 la ko ton tai nen loai bo tranh duyet vo nghia ")
    //day tan suat vao max-heap
    for (int i: a) {
        if (i>0) q.push(i);
    }
    
}
main() {

}

//so ky can loai bo
//xau ky tu dau vao
//dem tan suat xuat hien cua cac ky tu
//tang gtri tai vtri tuong ung vs ma ASCII cua ky tu
