//  author - Vishad Jain
//knapsack memoization code..

#include<bits/stdc++.h>
using namespace std;



int knapsack(int wt[],int val[],int n,int capacity){
	
	int dp[n][capacity];
	memset(dp,-1,sizeof(dp));
	if(n==0 || capacity==0){
		return 0;
	}
	
	if(wt[n-1]<=capacity){
		dp[n][capacity] = max(val[n-1] + knapsack(wt,val,n-1,capacity-wt[n-1]),knapsack(wt,val,n-1,capacity));	
	}
	else{
		dp[n][capacity] = knapsack(wt,val,n-1,capacity);
	}
	int ans = dp[n][capacity];
	return ans;
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