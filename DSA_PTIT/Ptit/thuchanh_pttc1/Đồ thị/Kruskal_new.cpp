#include <bits/stdc++.h>
using namespace std;
struct canh{
	int dau, cuoi, ts;
};
int cmp(canh a, canh b){
	return a.ts < b.ts;
}
int parent[1005], num[1005];
void init(int n){
	for (int i = 1; i <= n; i++){
		parent[i] = i; 	num[i] = 1;
	}
}
int Find(int u){
	if (u == parent[u]) return u;
	return Find(parent[u]);
}
int Union(int u, int v){
	int a = Find(u), b = Find(v);
	if(a == b) return 0;
	if (num[a] < num[b]) swap(a,b);
	parent[b] = a;
	num[a] += num[b];
	return 1;
}
main(){
	int t,n,m,i,dau, cuoi, ts;
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<canh> ds; ds.clear();
		for (i = 0; i < m; i++){
			cin >> dau >> cuoi >> ts;
			ds.push_back({
				dau,cuoi,ts
			});
		}
		sort(ds.begin(),ds.end(),cmp);
		init(n);
		int kq = 0, dem = 0;;
		for (i = 0; i < ds.size(); i++){
			if (Union(ds[i].dau,ds[i].cuoi)){
				dem++;
				kq += ds[i].ts;
			}
			if(dem==n-1) break;
		}
		cout << kq << endl;
	}
}
