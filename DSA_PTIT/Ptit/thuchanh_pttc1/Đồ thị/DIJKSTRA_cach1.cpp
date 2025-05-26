#include<bits/stdc++.h>
using namespace std;
int C[1005][1005], n;
void Dijkstra(int s){
	bool daxet[n+1] = {false};
	int d[n+1] = {0}, t = n-1, min, u, i;
	daxet[s] = true;
	for(i=1;i<=n;i++) d[i] = C[s][i];
	while(t--){
		min = INT_MAX; u = 0;
		for(i=1;i<=n;i++){
			if(!daxet[i] && min > d[i]){
				min = d[i];
				u = i;
			}
		}
		daxet[u] = true;
		for(i=1;i<=n;i++){
			if(d[i] > d[u] + C[u][i]){
				d[i] = d[u] + C[u][i];
			}
		}
	}
	for(i=1;i<=n;i++) cout << d[i] << " ";
	cout << endl;
}
main(){
	int t; cin >> t;
	while(t--){
		int m, s, i, j, u, v, w;
		cin >> n >> m >> s;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(i==j) C[i][j] = 0;
				else C[i][j] = 1e9;
			}
		}
		for(i = 0; i < m; i++){
			cin >> u >> v >> w;
			if(C[u][v] > w) C[u][v] = C[v][u] = w;
		}
		Dijkstra(s);
	}
}
