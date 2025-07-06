// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều rộng bắt đầu tại đỉnh uÎV (BFS(u)=?)
//
// Input:
//
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào ba số |V|, |E|, uÎV tương ứng với số đỉnh, số cạnh và đỉnh bắt đầu duyệt; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
//
// Output:
//
// Đưa ra danh sách các đỉnh được duyệt theo thuật toán BFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
//
// Ví dụ:
// Input:
// 1
//
// 6 9 1
//
// 1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6
// Output:
// 1 2 3 5 4 6
#include<bits/stdc++.h>
using namespace std;
vector<int> List[1005];
int daxet[1005];

void BFS(int u){
	queue<int> Q;
	Q.push(u); daxet[u] = 1;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		cout << x << " ";
		for(int i: List[x]){
			if(!daxet[i]){
				daxet[i] = 1; Q.push(i);
			}
		}
	}
	cout << endl;
}

main(){
	int t; cin>>t;
	while(t--){
		for(int i = 0; i < 1005; i++){
			daxet[i] = 0; List[i].clear();
		}
		int n,m,u;
		cin >> n >> m >> u;
		for(int i = 0; i < m; i++){
			int x,y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		BFS(u);
	}
}
