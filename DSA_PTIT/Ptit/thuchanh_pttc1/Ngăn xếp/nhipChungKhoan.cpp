// Bạn là một nhà đầu tư chứng khoán nổi tiếng.
// Nhiệm vụ hàng ngày của bạn là tính nhịp tăng giảm
// của phiên chứng khoán trong N ngày để có thể bắt kịp thị trường.
// Nhịp chứng khoán của ngày thứ i được định nghĩa là số ngày liên tiếp từ ngày
// thứ i trở về mà giá chứng khoán bé hơn hoặc bằng với giá chứng khoán của ngày i.
// Input: Dòng đầu ghi số bộ test (không quá 10). Mỗi test có 2 dòng.
// Dòng đầu tiên gồm 1 số nguyên N (1 ≤ N ≤ 105) là số ngày.
// Dòng tiếp theo gồm N số nguyên A1, A2, …, AN (1 ≤ Ai ≤ 106) là giá chứng khoán của các ngày.
// Output
// In ra N số B1, B2, ..., BN trong đó Bi là nhịp chứng khoán của ngày thứ i.
// Ví dụ:
// Input
// 1
// 7
// 100 80 60 70 60 75 85
// Output
// 1 1 1 2 1 4 6

#include <bits/stdc++.h>
using namespace std;

main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n+1];
        for (int i=1; i<=n;i++) {
            cin>>a[i];
        }
        stack<int> st;
        for (int i=1; i<=n;i++) {
            // !st.empty(): Kiểm tra stack không rỗng, tức là có ít nhất một ngày để so sánh.
            // a[st.top()] <= a[i]: Giá của ngày ở đỉnh stack (a[st.top()]) nhỏ hơn hoặc bằng giá ngày hiện tại (a[i]).
            // Nếu cả hai đúng, thực hiện st.pop() để xóa ngày ở đỉnh stack.
            while (!st.empty() && a[st.top()]<=a[i]) st.pop();
            if (st.empty()) cout<<i<<" ";
            else cout<<i-st.top()<<" ";
            st.push(i);
        }
        cout<<"\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
main() {
    int t,n,a[100005];
    stack <int> st;
    cin >> t;
    while(t--) {
        cin >> n;  	st.push(0);
        for(int i=1;i<=n;i++) {
            cin >> a[i];
            while(st.size() > 1 && a[st.top()] <= a[i]) st.pop();
            cout << i - st.top() << " ";
            st.push(i);
        }
        while(st.size()) st.pop();
        cout << endl;
    }
}


// #include <bits/stdc++.h>
// using namespace std;
// main(){
//     int t, n, a[100005];
//     stack <int> st;
//     cin>>t;
//     while (t--){
//         cin>>n;
//         while (st.size()) st.pop();
//         st.push(0);
//         for(int i=1;i<=n;i++){
//             cin>>a[i];
//             while (st.size()>1&&a[st.top()]<=a[i]) st.pop();
//             cout<<i-st.top()<<" ";
//             st.push(i);
//         }
//         while (st.size()) st.pop();
//         cout<<'\n';
//     }
// }