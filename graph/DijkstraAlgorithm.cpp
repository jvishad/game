#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;


int find(int **edges,int V,bool*visited,int * weight){
    int minVertex = -1;
    for(int i=0;i<V;i++){
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void Dijkstra(int** edges,int V,int E,int st){
    
    bool* visited = new bool[V];
    int* parent = new int[V];
    int* weight = new int[V];
    
    for(int i=0;i<V;i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    
    parent[0] = -1;
    weight[0] = 0;
    
    for(int i=0;i<V;i++){
        int minVertex = find(edges,V,visited,weight);
        visited[minVertex] = true;
        
        for(int j=0;j<V;j++){
            if(!visited[j] && edges[minVertex][j]>0){
                if(weight[minVertex] + edges[minVertex][j] < weight[j]){
                    weight[j] = weight[minVertex] + edges[minVertex][j];
                }
        	}
    	}
    }
    
    for(int i=0;i<V;i++){
        cout << i << " " << weight[i] << endl;
    }
    delete[] parent;
    delete[] visited;
    delete[] weight;
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
    
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a][b] = c;
        edges[b][a] = c;
    }
    
    Dijkstra(edges,V,E,0);
    
}
