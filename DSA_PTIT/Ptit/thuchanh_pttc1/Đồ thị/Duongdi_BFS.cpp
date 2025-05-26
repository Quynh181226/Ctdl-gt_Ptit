#include <bits/stdc++.h> 
using namespace std; 
int a[1005][1005];
bool chuaxet[1005];
int n, m, u, v, truoc[1005];
void BFS(int u){
    queue<int> q;
    q.push(u);
    chuaxet[u] = false;
    while (!q.empty()){
        int t = q.front(); q.pop();
        for (int v = 1; v <= n; v++)
            if (chuaxet[v] && a[t][v]){
                truoc[v] = t;
                chuaxet[v] = false;
                q.push(v);
            }
    }
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
	cin >> t;
	while (t--){
		memset(a, 0, sizeof(a));
		memset(chuaxet,true,sizeof(chuaxet));
		memset(truoc,0,sizeof(truoc));

		cin >> n >> m >> u >> v;
 		for (i = 1; i <= m; i++){
   	    	cin >> x >> y;
    	    a[x][y] = 1;
    		a[y][x] = 1;
    	}
    	BFS(u);
    	if(chuaxet[v]==true) cout<<-1<<endl;
		else induongdi();
	}
}
