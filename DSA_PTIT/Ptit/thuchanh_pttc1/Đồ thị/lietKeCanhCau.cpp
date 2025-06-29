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
void canhcau(){
    int i,j,k,u;
	for (i=1; i<=n; i++) {
		for(u=0; u<List[i].size(); u++){
            j = List[i][u];

            List[i].erase(List[i].begin()+u);

            DFS(i);
            bool check = false;
            for(k=1;k<=n;k++) if(chuaxet[k]) check=true;
            if (check && i<j) cout << i << " "<<j<<" ";

            List[i].insert(List[i].begin()+u,j);

            memset(chuaxet,true,sizeof(chuaxet));
		}
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
		canhcau(); cout<<endl;
	}
}
