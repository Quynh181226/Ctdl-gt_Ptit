//
// Created by TDG on 09/07/2025.
//
// ĐÂY LÀ CÁCH MÀ CHƯA TỐI ƯU
#include<bits/stdc++.h>
using namespace std;
//tìm và gộp
//ktra xem 2 đỉnh 2 phần tử nó có cùng 1 tập hợp hay không
//và nó giúp gộp 2 cái đó thành 1 tập hợp
//kiểu như kết bạn a chơi với b b chơi với c vậy
//hoặc như bài toán công viên -> có người đại diện là bao nhiêu, và nó có cùng tập hợp ko
//kiểu phải xét người đại diện kiểu phải ko cùng nhóm với nhau cơ
//còn mà cùng rồi thì ko cần gộp

//có thể là hiện tại cái nhóm này chỉ là người đại diện tạm thời thôi
//nhg khi dsu hoạt động nó sẽ tìm ra đc người đại diện thực sự -> nhóm trưởng của nhóm
//DSU là 1 ctruc dlieu tự xây
// mảng lưu người đại diện parent -> p
// mỗi 1 đỉnh thì coi đó là 1 ptu trg tập hợp

//khởi tạo cho cấu trúc dữ liệu cho dsu thì ta phải cho tất cả các đỉnh i = i
//ban đầu có n thằng mỗi thằng đại diện cho 1 tập hợp nên đại diện của nó sẽ là chính nó
int n, m, parent[100001];
void Init(){
    for(int i=0; i<=n; i++) parent[i] = i;
}
//tìm va gop: find và union: thao tác
//người đại diện nó vs cha của nó là giống nhau
//từ đỉnh u cứ //lần ngược lại// đến bao giờ gặp cái đỉnh mà cha của nó giống nhau
//thì đó là đại diện thực sự cho u -> tìm được cha của đỉnh u
int Find(int u){
    while(parent[u] != u) u = parent[u];
return u;
}
//muốn gộp thì phải đi tìm người đại diện
bool Union(int x, int y){
    x=Find(x);
//tìm xem người đại diện của x là gì
    y=Find(y);
//-> đã nằm trg cùng 1 tập hợp rồi thì ko ohair gộp nx
    if(x==y) return false;
    if(x<y) parent[y]=x;
    else parent[x]=y;
    return true;
}

//1. dùng để đến số lg thành phần liên thông của đồ thị
// - ví dụ khi bạn nhập 2 cạnh giống như vc gộp 2 tplt đó lại vs nhau
//2. check dc chu trình trên đồ thị vô hướng/
// - đó là thời điểm mà mình cứ gộp 2 cạnh đấy vào vs nhau mà không gộp đc
// - thì đó là lúc nó xuất hiện chu trình

//    VÍ DỤ CODE NÀY VS BÀI ĐẾM TPLT
main(){
    cin>>n>>m;
    int ans=n;//số lg tplt của đồ thị ban đầu
    Init();
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        //mỗi lần nhập cạnh x, y mà gộp đc 2 thằng đấy lại vs nhau
        //=> giảm số tplt của đồ thị đi 1
        if(Union(x,y)) --ans;
    }
    cout<<ans<<endl;
}
//  => KẾT LUẬN COI ĐỒ THỊ NHƯ TẬP HỢP
// => ĐẾM ĐC TPLT