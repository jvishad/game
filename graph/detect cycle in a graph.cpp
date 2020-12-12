#include<bits/stdc++.h>
using namespace std;

vector<int> ar[100001];
bool vis[100001] = {false};

bool dfs(int u,int parent){
	vis[u] = true;
	for(auto it:ar[u]){
		if(!vis[it]){
			bool cycle_mila = dfs(it,u);
			if(cycle_mila>0){
				return true;
			}
		}
		else{
			if(it!= parent){
				return true;
			}
		}
	}
	return false;
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	bool res = dfs(1,-1);
	if(res) cout<< "mila" << endl;
	else cout<< " nahi mila" <<endl;
	return 0;
}