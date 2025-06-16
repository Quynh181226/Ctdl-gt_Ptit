//
// Created by TDG on 28/05/2025.
//
#include<bits/stdc++.h>
using namespace std;

//số vé của từng người
vector<int> tickets;
int solve(int k) {
    //chỉ số của đại diện cho nhg người đg xếp hàng
    queue<int> q;
    for (int i=0;i<tickets.size();i++){
        q.push(i);
    }
    int time=0;
    while (!q.empty()) {
        time++;
        int front=q.front();
        q.pop();
        tickets[front]--; // Người đó mua 1 vé
        if (k==front&&tickets[front]==0) {
            // Nếu là người cần theo dõi và họ đã mua hết vé → trả về thời gian
            return time;
        }
        if (tickets[front]!=0) {
            // Nếu người đó còn vé thì đưa họ về cuối hàng
            q.push(front);
        }
    }
    return time;
}

main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    tickets.resize(n);
    for (int i=0;i<n;i++) {
        cin>>tickets[i];
    }
    cout<<solve(k);
}







#include<bits/stdc++.h>
using namespace std;

vector<int> tickets;
int solve1(int k) {
    queue<int> q;
    for (int i=0;i<tickets.size();i++) {
        q.push(i);
    }
    int time = 0;
    while (!q.empty()){
        time++;
        int front=q.front();
        q.pop();
        tickets[front]--;
        if (k==front && tickets[front]==0) {
            return time;
        }
        if (tickets[front]!=0) {
            q.push(front);
        }
    }
    return time;
}

vector<int> tickets1;
int solve2(int k) {
    int time=0;
    for (int i=0;i<tickets1.size();i++) {
        // Người này đứng trước hoặc chính là người k
        // Họ sẽ được mua tối đa min(tickets[i], tickets[k]) lần
        if (i<=k) time+=min(tickets1[i], tickets1[k]);
        // Người này đứng sau người k
        // Họ chỉ được phục vụ tối đa (tickets[k] - 1) lần
        else time+=min(tickets1[i], tickets1[k]-1);
    }
    return time;
}

vector<int> tickets2;
int solve3(int k) {
    int i=0, cnt=0;
    while (tickets2[k]>0) {
        if (tickets2[i]) {
            cnt++;
            tickets2[i]--;
        }
        if (i==tickets2.size()-1) i=0;
        else i++;
    }
    return cnt;
}

int main() {
    int n, k;
    cout << "Nhập số người và vị trí k: ";
    cin >> n >> k;

    tickets.resize(n);
    tickets1.resize(n);
    tickets2.resize(n);

    cout << "Nhập số vé mỗi người cần mua:\n";
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        tickets[i] = tickets1[i] = tickets2[i] = t;
    }

    cout << "\nKết quả:\n";
    cout << "solve1 (giả lập hàng đợi):      " << solve1(k) << endl;
    cout << "solve2 (tính ttiep theo min):    " << solve2(k)<< endl;
    cout << "solve3 (mô phỏng vòng tròn):     " << solve3(k) << endl;
    return 0;
}