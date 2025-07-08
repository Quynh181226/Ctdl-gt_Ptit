#include<bits/stdc++.h>
using namespace std;
main(){
	int t; cin >> t;
	cin.ignore();
	while(t--){
		string s; getline(cin,s);
		int dem = 1;
		stack<int> st;
		for(int i=0;i<s.length();i++){
			if(s[i]=='('){
				st.push(dem);
				cout << st.top() << " ";
				dem++;
			}
			else if(s[i]==')'){
				cout << st.top() << " ";
				st.pop();
			}
		}
		cout << endl;
	}
}
