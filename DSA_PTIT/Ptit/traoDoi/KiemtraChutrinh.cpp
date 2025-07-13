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
bool Union(int u, int v){
    int a = Find(u), b = Find(v);
	if(a == b) return 0;
	if (num[a] < num[b]) swap(a,b);
	parent[b] = a;
	num[a] += num[b];
	return 1;
}
main() {
    int t,u,v,i; cin >> t;
    while(t--){
        cin >> n >> m;
        init(); bool check = false;
        while(m--){
            cin >> u >> v;
            if(!Union(u, v)) check = true;
        }
		if(check==true) cout<<"YES"<<endl;
		else cout << "NO" << endl;
    }
}
