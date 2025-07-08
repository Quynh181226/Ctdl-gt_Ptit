#include <bits/stdc++.h>
using namespace std;
int n, m, parent[100001], num[100001];
void init(){
    for(int i=1; i<=n; i++){
        parent[i] = i;
        num[i] = 1;
    }
}
int Find(int u){
    if(u != parent[u])
        parent[u] = Find(parent[u]);
    return parent[u];
}
void Union(int u, int v){
    int a = Find(u), b = Find(v);
	if(a == b) return;
	if (num[a] < num[b]) swap(a,b);
	parent[b] = a;
	num[a] += num[b];
}
main() {
    int t,u,v,i; cin >> t;
    while(t--){
        cin >> n >> m;
        init();
        while(m--){
            cin >> u >> v;
            Union(u, v);
        }
		int dem = 0;
		for(i=1;i<=n;i++)
            if(i==parent[i]) dem++;
        cout << dem << endl;
    }
}
