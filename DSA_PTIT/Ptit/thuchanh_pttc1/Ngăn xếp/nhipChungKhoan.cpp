#include <bits/stdc++.h>
using namespace std;

int t, n, a[100005];
stack<int> st;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        st.push(0); 
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            while (st.size() > 1 && a[st.top()] <= a[i]) {
                st.pop();
            }
            printf("%d ", i - st.top());
            st.push(i);
        }
        printf("\n");
        while (!st.empty()) st.pop();
    }
    return 0;
}
