// author - Vishad Jain
//knapsack problem -- count subset sum problem using top down approach.

//  *Given an array,you have to find the no of subset having that having the sum equal to the given value.
// output pattern -- interger value.

#include<bits/stdc++.h>
using namespace std;


int subset_sum(int wt[],int n,int sum){
	
	int dp[n+1][sum+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0){
				dp[i][j]=0;
			}
			if(j==0){
				dp[i][j]=1;
			}
		}	
	}
	dp[0][0]=1;
	// we are saving the precomputed result in the 2d array.
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(wt[i-1]<=j){
				dp[i][j] = dp[i-1][j-wt[i-1]] + dp[i-1][j];	
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][sum];
}

int main()
{
	int n=6;
	int wt[6]={2,3,5,6,8,10};
	int sum = 10;
	int ans = subset_sum(wt,n,sum);
	cout<<ans<<endl;
	return 0;
}
