#include<bits/stdc++.h>
using namespace std;
int n,m;
bool chuaxet[1005];
vector<int> List[1005];
void DFS(int u){
	chuaxet[u]=false;
	for(int i=0; i<List[u].size(); i++){
        int v = List[u][i];
        if(chuaxet[v]) DFS(v);
	}
}
void dinhtru(){
    int i,u;
	for (u=1; u<=n; u++) {
		chuaxet[u] = false;
		if (u== 1) DFS(2);
		else DFS(1);

		bool check = false;
		for(i=1;i<=n;i++)
            if(chuaxet[i]) check=true;
		if (check) cout << u << " ";
		memset(chuaxet,true,sizeof(chuaxet));
	}
}
main(){
	int t,x,y,i;
	cin>>t;
	while(t--){
		memset(chuaxet,true,sizeof(chuaxet));
		for(i=0;i<1005;i++) List[i].clear();
		cin>>n>>m;
		for(i=1;i<=m;i++){
			cin>>x>>y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		dinhtru(); cout<<endl;
	}
}
