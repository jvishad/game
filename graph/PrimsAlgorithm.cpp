#include <iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

int find(int V,bool *visited,int *weight){
    int minVertex = -1;
    for(int i=0;i<V;i++){
        if(!visited[i] && (minVertex == -1 || weight[minVertex] > weight[i])){
            minVertex = i;
        }
    }
    return minVertex;
    
}


void prims(int **edges,int V,int E){
    
    bool *visited = new bool[V];
    int *weight = new int[V];
    int *parent = new int[V];
    
    for(int i=0;i<V;i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    
    weight[0] = 0;
    parent[0] = -1;
    
	for(int i=0;i<V;i++){
        
        int minVertex = find(V,visited,weight);
        visited[minVertex] = true;
        for(int j=0;j<V;j++){
        	if(edges[minVertex][j]!=0 && visited[j]==false){
                if(weight[j] > edges[minVertex][j]){
        			weight[j] = edges[minVertex][j];
            		parent[j] = minVertex;
                }
            }
        }
    }
	
    
    for(int i=1;i<V;i++){
        cout << min(i,parent[i]) << " " << max(i,parent[i]) << " " << weight[i] << endl;
    }
    
    
}

int main() {
    // Write your code here
     int V,E;
     cin>>V>>E;
    int **edges = new int*[V];
	for(int i=0;i<V;i++){
        edges[i] = new int[V];
		for(int j=0;j<V;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int k=0;k<E;k++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges[a][b] = c;
        edges[b][a] = c;
    }
    
    prims(edges,V,E);
}
