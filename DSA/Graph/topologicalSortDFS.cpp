#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<stack>

using namespace std;

void topoSort(int node,  vector<bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s){
    visited[node] = true;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour])
        topoSort(neighbour, visited, adj, s);
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e){
    
    // create adjacency matrix
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }

    vector<bool> visited(V);
    stack<int> s;
    // call dfs topological sort 
    for(int i=0; i<V; i++){
        if(!visited[i]){
            topoSort(i, visited, adj, s);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}