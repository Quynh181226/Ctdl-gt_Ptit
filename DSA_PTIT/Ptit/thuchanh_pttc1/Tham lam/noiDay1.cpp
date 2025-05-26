//
// Created by TDG on 24/05/2025.
//
// Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].
// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào số lượng sợi dây N; dòng tiếp theo đưa vào N số A[i] là độ dài của các sợi dây; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤106; 0≤A[i]≤106.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
// Input
// 2
// 4
// 4 3 2 6
// 5
// 4 2 7 6 9
// Output
// 29
// 62

#include<bits/stdc++.h>
using namespace std;

main() {
    long long t, n, x, min1, min2;
    cin>>t;
    if (t<1||t>100) return 1;
    while (t--) {
        cin>>n;
        if (n<1||n>1000000) continue;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        bool check = true;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x < 0 || x > 1000000) check = false;
            pq.push(x);
        }
        if (!check) continue;
        long long cnt=0, ans=0;
        while (pq.size()>1) {
            min1=pq.top(); pq.pop();
            min2=pq.top(); pq.pop();

            ans=min1+min2;
            cnt=cnt+ans;

            pq.push(ans);
        }
        cout<<cnt<<endl;
    }
}
