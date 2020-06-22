        //author - vishad0198@gmail.com
        //those who can't remember the past are condemned to repeat it

#include<bits/stdc++.h>
#include<queue>
using namespace std;
//nearby or ksorted array 
//classical problem based on heap
//priority_queue is the used stl

void nearby_sorted(int input[] ,int size ,int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    int j=0;
    for(int i=k;i<size;i++){                       
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.empty()){
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}
//priority_queue always works in the descending order so in order to make it ascending we will use 
// priority_queue<int,vector<int>,greater<int>>pq;
int main()
{
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int k;
    cin>>k;
    nearby_sorted(input,n,k);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}