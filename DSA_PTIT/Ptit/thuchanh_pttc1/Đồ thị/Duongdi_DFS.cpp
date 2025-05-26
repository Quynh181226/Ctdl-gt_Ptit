#include<bits/stdc++.h>
using namespace std; 
bool chuaxet[1005];
vector<int> List[1005];
int truoc[1005], n,m,u,v;
void DFS(int u){
	chuaxet[u]=false;
	for(int i=0; i<List[u].size(); i++){
        int v = List[u][i];
        if(chuaxet[v]){
			truoc[v] = u; DFS(v);
		}
	}
}
void BFS(int u){
	queue<int> Q;
	Q.push(u); chuaxet[u]=false;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		cout << x << " ";
		for(int i: List[x]){
			if(chuaxet[i]){
				chuaxet[u]=false; Q.push(i);
			}
		}
	}
	cout << endl;
}
void induongdi(){
    stack <int> st;
    st.push(v);
    while(st.top()!=u){
        int t=st.top();
        st.push(truoc[t]);
    }
    while(!st.empty()){
        int t=st.top();st.pop();
        cout<<t<<" ";
    }
    cout<<endl;
}

main(){
	int t,i,x,y;
	cin>>t;
	while(t--){
		for(i=0;i<1005;i++)	List[i].clear();
		memset(chuaxet,true,sizeof(chuaxet));
		memset(truoc,0,sizeof(truoc));
		cin>>n>>m>>u>>v;
		for(i=0;i<m;i++){
			cin>>x>>y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		DFS(u);
		if(chuaxet[v]==true) cout<<-1<<endl;
		else induongdi();
	}
}
