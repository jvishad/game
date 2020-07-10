// author - Vishad Jain
//knapsack top-down code..

#include<bits/stdc++.h>
using namespace std;


// just need to change some of the function call into the array and the final code changes out to the dp(top down approach).
int knapsack(int wt[],int val[],int n,int capacity){
	
	int dp[n+1][capacity+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<capacity+1;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
		}	
	}
	// we are saving the precomputed result in the 2d array.
	for(int i=1;i<n+1;i++){
		for(int j=1;j<capacity+1;j++){
			if(wt[i-1]<=j){
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);	
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][capacity];
}

int main()
{
	int n=5;
	int wt[5]={1,5,3,9,3};
	int val[5] = {1,3,1,5,100};
	int capacity = 6;
	cout<<knapsack(wt,val,n,capacity)<<endl;
	return 0;
}

// formal discussion 
// ---time complexity of top down approach and memoization is nearly equal in some cases top down approach
//  more suitable while in other memoization is more suitable.