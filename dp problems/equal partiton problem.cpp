// author - Vishad Jain
//Equal sum partition using top-down code..

// problem statement.
// -- Given an array of size n, you need to find whether that array can we divided into two equal halves or not.
// if we can print "Yes" else print "No".


#include<bits/stdc++.h>
using namespace std;


bool subset_sum(int wt[],int n,int sum){
 
	int dp[n+1][sum+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0){
				dp[i][j]=false;
			}
			if(j==0){
				dp[i][j]=true;
			}
		}	
	}
	dp[0][0]=true;
	// we are saving the precomputed result in the 2d array.
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(wt[i-1]<=j){
				dp[i][j] = dp[i-1][j-wt[i-1]] || dp[i-1][j];	
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
 
	return dp[n][sum];
}

bool equal_sum(int wt[],int n , int target){
	return subset_sum(wt,n,target/2);
}

int main()
{
	int n=6;
	int wt[6]={1,2,3,4,5,16};
	int size = sizeof(wt)/sizeof(wt[0]);
	int target = 0;
	for(int i=0;i<size;i++){
		target += wt[i];
	}
	if(target&1){
		cout<<"No"<<endl;
	}
	else{
		bool ans = equal_sum(wt,n,target);
		if(ans == true){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}