#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> l[1001];
bool visited[1001];


void dfs(int u){
    visited[u] = true;
    for(auto it:l[u]){
        if(!visited[it]){
            dfs(it);
        }
    }
}

int main() {
    // Write your code here
    int V,E;
    cin>>V>>E;
    
    for(int i=0;i<E;i++){
    	int x,y;
        cin>>x>>y;
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    int count = 0;
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }
    
    cout<< count << endl;
    return 0;
}
