//
// Created by TDG on 09/07/2025.
//
// ĐÂY LÀ CÁCH ĐÃ TỐI ƯU
// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm số thành phần liên thông của đồ thị.
//
// Input:
//
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
//
// Output:
//
// Đưa ra số thành phần liên thông của đồ thị.
//
// Ví dụ:
// Input:
// 1
// 5 6
// 1 2 1 3 2 3 3 4 3 5 4 5
// Output:
// 1
#include<bits/stdc++.h>
using namespace std;
int n, m, max_val=1, parent[100001], sz[100001];
void Init(){
    for(int i=1; i<=n; i++) {
        parent[i] = i;
        //Ban Đầu N Đỉnh Đứng Riêng Lẻ Vs Nhau
        //=> size = 1
        sz[i] = 1;
    }
}
// => ĐÂY LÀ TỐI ƯU NÉN ĐƯỜNG NÓ SẼ GIÚP ĐỈNH TRÊN ĐƯỜNG ĐI
// CỦA BẠN NGẮN LẠI TRONG QUÁ TRINHG TÌM NGƯỜI ĐẠI DIỆN
int Find(int u){
//     while(parent[u] != u) u = parent[u];
// return u;
    // nếu n là người đại diện
    if (u==parent[u]) return u;
    //với câu lệnh này nó sẽ tìm parent của u trước sau đó nó mới gán lại cho parent của u
    //code cụ thể
    // int x=parent[u];
    // parent[u] = x;
    // return x;
    //Code Nén Đường
    return parent[u] = Find(parent[u]);
}
//hàm Union htai cứ thằng nào nhỏ hơn thằng đấy làm người đại dịện
//nhung bây giờ ta sẽ sử dụng cách tối ưu gộp
//img minh họa demo.md dòng 5
//NÓI NÔM NA LÀ VÍ DỤ TRONG HÌNH CÓ 2 TẬP HỢP THÌ TA SẼ GỘP 2 TẬP HỢP ĐÓ V VS NHAU
//MÀ THẰNG 1 CÓ NHIỀU ĐỈNH, PTU, BLA HƠN -> ĐỔI ĐẠI DIỆN CỦA 8 THÀNH 1
//->GỘP T/CONG
//==> ĐỂ TRÁNH THAY ĐỔI CHO TẬP HƠN CÓ NHIỀU PHẦN TỬ HƠN
//=> Cần 1 Mảng xem mỗi tập hợp có bao nhiêu phần tử đặt là sz, num[100001] đều đc
bool Union(int x, int y){
    x=Find(x);
    y=Find(y);
    if(x==y) return false;
    // if(x<y) parent[y]=x;
    // else parent[x]=y;
    // if else này là code cho 34, 35
    //là gộp 2 thằng lại vs nhau và + tập hợp của chúng lại = tập hợp ms
    if(sz[x]<sz[y]) {
        parent[x]=y;
        sz[y]+=sz[x];
    }else {
        parent[y]=x;
        sz[x]+=sz[y];
    }
    return true;
}
main(){
    cin>>n>>m;
    // int ans=n;
    //biến ktra phát hiên chu triình
    bool check=false;
    Init();
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        if(!Union(x,y)) check=true;
    }
    // cout<<ans<<endl;
    if (check) cout<<1<<endl;
    else cout<<0<<endl;
}