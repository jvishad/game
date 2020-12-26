#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int source;
    int dest;
    int weight;
};

bool cmp(Edge e1,Edge e2){
	return e1.weight < e2.weight;
}


int	findParent(int a,int* parent){
    if(parent[a]==a){
        return a;
    }
    return findParent(parent[a],parent);
}

int main() {
    // Write your code here
    int V,E;
    cin>>V>>E;
    Edge input[E];
    int parent[V];
    
    for(int i=0;i<E;i++){
        cin>>input[i].source;
        cin>>input[i].dest;
        cin>>input[i].weight;
    }
    
    
    for(int i=0;i<V;i++){
        parent[i] = i;
    }
    
    sort(input,input+E,cmp);
    
    
    int count = 0;
    int i=0;
    while(count != (V-1)){
        int s = input[i].source;
        int d = input[i].dest;
        
        int parent1 = findParent(s,parent);
        int parent2 = findParent(d,parent);
        
      
        if(parent1!= parent2){
            cout << min(s,d) << " " << max(s,d) << " " << input[i].weight << endl;
            count++;
            parent[parent1] = parent2;
            
        }
        i++;
        
    }
}
