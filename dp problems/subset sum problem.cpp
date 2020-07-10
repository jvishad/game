// author - Vishad Jain
//knapsack problem -- subset sum problem using top down approach.

//  *here an array consist of the weight of some given no of elements, we need to find whether a given 
// sum of any one the subset becomes equal to the given sum 
// output  pattern  -- If there exist any print "Yes" else print "No".

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

int main()
{
	int n=5;
	int wt[5]={1,5,3,9,3};
	int sum = 22;
	bool ans = subset_sum(wt,n,sum);
	if(ans==true){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}
