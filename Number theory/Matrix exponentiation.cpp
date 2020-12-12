#include <bits/stdc++.h>
using namespace std;

void multiply(int m1[2][2],int m2[2][2]){
	int first = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];
	int second = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
	int third = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
	int fourth = m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];
	m1[0][0] = first;
	m1[0][1] = second;
	m1[1][0] = third;
	m1[1][1] = fourth;
}

void power(int a[][2],int n){                                   
	int m[2][2] = {{1,1},{1,0}};							 
	if(n==0|| n==1){
		return;
	}
	power(a,n/2);
	
	multiply(a,a);
	if(n%2){
		
		multiply(a,m);
	}
	return;
}

int fib(int n){
	int a[2][2]  = {{1,1},{1,0}};
	if(n==0){
		return 0;
	}
	
	power(a,n-1);
	
	return a[0][0];
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	cout<<fib(10) << endl;
	return 0;
}
