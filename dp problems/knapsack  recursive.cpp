// author - Vishad Jain
//knapsack recursive code..

#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int n,int capacity){

	if(n==0 || capacity==0){
		return 0;
	}
	if(wt[n-1]<=capacity){
		return max(val[n-1] + knapsack(wt,val,n-1,capacity-wt[n-1]),knapsack(wt,val,n-1,capacity));	
	}
	else{
	return knapsack(wt,val,n-1,capacity);
	}
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