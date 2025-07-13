//
// Created by TDG on 09/07/2025.
//
// [Graph]. Bài 42. Lát đường
// Ở 28techland có n thành phố và ban đầu không có đường giữa chúng. Tuy nhiên,
// mỗi ngày một con đường mới sẽ được xây dựng và sẽ có tổng cộng m con đường.
// Một cụm thành phố là một nhóm các thành phố trong đó có một tuyến đường
// giữa hai thành phố bất kỳ bằng cách sử dụng các con đường. Sau mỗi ngày,
// nhiệm vụ của bạn là tìm ra số lượng cụm thành phố và kích thước của cụm thành
// phố lớn nhất.
// Input Format
// Dòng đầu tiên có hai số nguyên n và m: số thành phố và đường. Các thành phố
// được đánh số 1,2,..., n. Sau đó, có m dòng mô tả các con đường mới. Mỗi dòng có
// hai số nguyên a và b: một con đường mới được xây dựng giữa các thành phố a và
// b. Bạn có thể cho rằng mọi con đường sẽ được xây dựng giữa hai thành phố khác
// nhau.
// Constraints
// 1≤n≤10^5; 1≤m≤2⋅10^5; 1≤a,b≤n;
// Output Format
// In m dòng: thông tin cần thiết sau mỗi ngày.
// Sample Input 0
//5 tpho, 3 con đường                    // 5 3
                    // 1 2 // đây 2 thằng này
                    // 1 3 // <=>
                    // 4 5 //ĐÂY LÀ CÁCH GỘP 3 CON ĐƯỜNG TRG 3 NGÀY => KQUA
// Sample Output 0
// 4 2 // 4 là số lượng cụm thành phố (=> tplt của đồ thị khi đó là 4 // cụm thành phố có nhiều thành phố nhất là 2
// 3 3
// 2 3
//=>Bắt tìm ra kích thước của cụm thành phố lớn nhất
//nhìn vào input ta có thể thấy ban đầu nó cho 5 thành phố đứng vs nhau 1 cách riêng lẻ
//img minh họa ouput DÒNG 8 DEMO.MD


//Nhìn vào input 1 lần nữa lúc này mình nhập cạnh thứ nhất
//mk hãy xem 2 cạnh đó có gộp đc lại vs nhau hay ko
//nếu gộp đc thì giảm cụm tpho đi ( tức là giảm tplt đi )
//cụm thành phố có nhiều thành phố nhất lấy mảng size làm đại diện chẳng hạn
//khi đó phần tử lơn nhất có trg size đại diện cho cụm thành phố có nhiều thành phố nhất
//ban đầu cụm thành phố của mk là N
//BẢN CHÁT YÊU CẦU:
//đồ thị sau mỗi bước sau khi 2 đỉnh đó đc gộp lại vs nhau có
//bao nhiêu thành phần liên thông mà n chứa nhiều đỉnh nhất


// In ra m dòng, mỗi dòng tương ứng với trạng thái sau mỗi ngày (sau khi thêm một con đường mới).
// Mỗi dòng chứa hai số:
// Số lượng cụm thành phố (số thành phần liên thông).
// Kích thước của cụm thành phố lớn nhất (số thành phố trong thành phần liên thông lớn nhất).


// Ban đầu: Có 5 thành phố, không có đường nối, nên có 5 cụm thành phố (mỗi thành phố là một cụm riêng lẻ), và cụm lớn nhất có 1 thành phố.
// Ngày 1 (xây đường 1-2):
//       Thành phố 1 và 2 được nối, tạo thành cụm {1, 2}.
//       Các thành phố 3, 4, 5 vẫn là các cụm riêng lẻ.
// Tổng số cụm: 4 (cụm {1, 2}, cụm {3}, cụm {4}, cụm {5}).
// Cụm lớn nhất: {1, 2} có 2 thành phố.
// Output: 4 2.
// Ngày 2 (xây đường 1-3):
//       Thành phố 3 được nối với thành phố 1 (thuộc cụm {1, 2}), nên cụm này mở rộng thành {1, 2, 3}.
//       Các thành phố 4, 5 vẫn là các cụm riêng lẻ.
// Tổng số cụm: 3 (cụm {1, 2, 3}, cụm {4}, cụm {5}).
// Cụm lớn nhất: {1, 2, 3} có 3 thành phố.
// Output: 3 3.
// Ngày 3 (xây đường 4-5):
//       Thành phố 4 và 5 được nối, tạo thành cụm {4, 5}.
//       Cụm {1, 2, 3} không thay đổi.
// Tổng số cụm: 2 (cụm {1, 2, 3}, cụm {4, 5}).
// Cụm lớn nhất: {1, 2, 3} vẫn có 3 thành phố (cụm {4, 5} chỉ có 2 thành phố, nhỏ hơn).
// Output: 2 3.
#include <bits/stdc++.h>
using namespace std;
int n, m, max_val=1, parent[100001], sz[100001];
void Init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u) {
    if (u==parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
bool Union(int x, int y) {
    x=Find(x);
    y=Find(y);
    if (x==y) return false;
    if (sz[x]<sz[y]) {
        parent[x]=y;
        //y=y+x
        sz[y]+=sz[x];
        //cập nhật max_val vs sz[y] sau khi gộp
        max_val=max(max_val, sz[y]);
    }else {
        parent[y]=x;
        sz[x]+=sz[y];
        max_val=max(max_val, sz[x]);
    }
    return true;
}
main() {
    cin>>n>>m;
    // bool check=false;
    Init();
    //N cụm tpho mỗi cụm là 1
    int cnt=n;
    for (int i = 1; i <= m; i++) {
        int x,y; cin>>x>>y;
        if (Union(x,y)) --cnt;//giảm số luượng cụm nếu gộp thành công
        cout<<cnt<<" "<<max_val;
    }
}
int n,m, max_val=1,p[100001],sz[1000001];
void init() {
    for (int i=1; i<=n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}
int find(int u) {
    if (u!=p[u]) {
        p[u] = find(p[u]);
    }
    return p[u];
}
bool Union(int u, int v){
    int a=find(u), b=find(v);
    if (a==b) return false;
    if (a<b) {
        p[a]=b;
        sz[b]+=sz[a];
        max_val=max(max_val, sz[b]);
    }else{
        p[b]=a;
        sz[a]+=sz[b];
        max_val=max(max_val, sz[a]);
    }
    return true;
}
main() {
    int u, v, t, i; cin>>t;
    while (t--) {
        cin>>m,n;
        init(); int cnt=0;
       for (i=1; i<=m; i++) {
           cin>>u>>v;if (Union(u) ) cnt--;
           cout<<cnt<<" "<<max_val
       }

    }
}