#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int subs(string input,string output[]){
	if(input.size()==0){
		output[0] = "";
		return 1;
	}
	string smallcal = input.substr(1);
	int sz = subs(smallcal,output);
	for(int i=0;i<sz;i++){
		output[i+ sz] = input[0] + output[i];
	}
	return 2*sz;
}

int main()
{
	string s;
	cin>>s;
	string output[1000];
	int count = subs(s,output);
	for(int i=0;i<count;i++) {
		cout<<output[i] <<endl;
	}
}