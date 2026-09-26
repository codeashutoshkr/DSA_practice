/*
You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], 
along with an integer m. Your task is to find if it is possible to color the graph using at most m different colors 
such that no two adjacent vertices share the same color. 
Note: The graph is indexed with 0-based indexing.

Example:
Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
Output: true
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool isSafe(int node, int col, const vector<int>& color, const vector<vector<int>>& adj){
    
    //check if any connected neighbour has the same color 'col'
    for(int neighbour : adj[node]){
        if(color[neighbour] == col){
            return false;
        }
    }

    return true;
}

bool solve(int node, int v, int m, vector<int>& color, const vector<vector<int>>& adj){
    //Base Case: All vertices from 0 to v-1 are successfully colored!
    if(node == v){
        return true;
    }

    // Try all available colors from 1 to m for the current 'node'
    for(int c=1; c<=m; c++){
        if(isSafe(node, c, color, adj)){
            color[node] = c;
    // Recurse to color the next vertex
           if(solve(node+1, v, m, color, adj)){
            return true;
           }
           color[node] = 0;
        }
    }

    // If no color from 1 to m works for this node, return false
        return false;
}

bool graphColoring(int v, vector<pair<int,int>>& edges, int m){
    
    //Step 1: Build the adjacency list for the O(1) neighbour lookup
    vector<vector<int>> adj(v);
    for(auto& edge: edges){
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    //Array to store color assigned to each vertex (0 means uncolored)
    vector<int> color(v,0);
    //start coloring from vertex 0
    return solve(0, v, m, color, adj);
}