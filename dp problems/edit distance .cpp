author - Vishad Jain
email - vishad0198@gmail.com

// solved using top down approach
#include<bits/stdc++.h>
using namespace std;

int static dp[1001][1001];
int editdistance(string a,string b, int m,int n){
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			if(i==0){
				dp[i][j]=j;
			}
			if(j==0){
				dp[i][j]=i;
			}
		}
	}
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] =  dp[i-1][j-1];
			}
			else{
				dp[i][j] =  1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			}
		}
	}
	int ans = dp[m][n];
	return ans;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	string a,b;
	a = "vishad";
	b = "jain";
	int m = a.size();
	int n = b.size();
	 cout<<"The distance for dp is " << editdistance(a,b,m,n) << endl;
	
}

output = The distance for dp is 6
