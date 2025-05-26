#include <bits/stdc++.h>
using namespace std;
int n, m, start, D[1005];
vector<pair<int, int> > List[1005];
priority_queue<pair<int,int>, vector<pair<int,int> >,
                            greater<pair<int,int> > > Q;

void Dijkstra(int start){
	int i,u,v;
	for(i=1;i<=n;i++) D[i] = 1e9;
	D[start] = 0;
	while(!Q.empty()) Q.pop();
	Q.push({0,start});
	while(!Q.empty()){
		u = Q.top().second; Q.pop();
		for(i=0; i<List[u].size();i++){
			v = List[u][i].second;
			int d_u_v = List[u][i].first;
			if(D[u] + d_u_v < D[v]){
				D[v] = D[u] + d_u_v;
				Q.push({D[v], v});
			}
		}
	}
	for(i=1;i<=n;i++) cout << D[i] << " ";
    cout << endl;
}
main(){
    int t,i,u,v,w;
    cin >> t;
    while(t--){
        cin >> n >> m >> start;
        for(i=0;i<=n;i++) List[i].clear();
        for(i=1;i<=m;i++){
            cin >> u >> v >> w;
            List[u].push_back({w,v});
            List[v].push_back({w,u});
        }
        Dijkstra(start);
    }
}
