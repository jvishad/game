                     //    VISHAD JAIN
                    // vishad0198@gmail.com 
                    //   be your own anchor
 
//  To find -- by traversing using dfs whether we are able to reach from one point to another
#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
#define ll long long 
#define ff first
#define ss second
#define pb push_back
#define FOR(i,o,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define vi vector<int>
#define vl vector<ll> 
#define mod 1000000007
#define pi 3.141592653589793238
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const int N = 1e6+3;
vector<int> g[N];
bool vis[N];

void dfs(int u){
	
	vis[u] = true;
	for(auto it:g[u]){
		
		if(!vis[it]) {
		dfs(it);
		}
	}	
}

int main()
{
	fast
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	if(vis[6]) cout<<"Connected"<<endl;
	else {
		cout<<"Not Connected"<<endl;
	}
	return 0;
}

// _____________________________________________________________________________
// input
// 4 5
// 1 2
// 2 3
// 3 4 
// 4 6
 

//______________________________________________________________________________
// Output
// Connected