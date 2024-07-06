#include<bits/stdc++.h>
using namespace std;

// DFS : Depth First Search
// recursion and backtracking
// stack
// T.C : O(V) + O(2E) ~ O(V + E)
// O(V) is for check all nodes visited
// O(2E) is sum of all degrees
// degree of node means no of vertices connected to that node
// S.C : O(V) recusion stack + O(V) result storing + O(V) visited ~ O(V) 

class Solution {
  private:
  
    void fun(int i, vector<int> adj[], vector<int>&vis, vector<int>&dfs){
        vis[i] = 1;
        dfs.push_back(i);
        
        for(auto it: adj[i]){
            // this is base condition for recursion 
            // without this infinite loop
            if(!vis[it]){
                fun(it,adj,vis,dfs);
            }
        }
        
    }
    
    
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        vector<int>dfs;
        
        // if graph is not connected then we use loop
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                fun(i, adj, vis, dfs);
            }
        }
        
        return dfs;
    }
    
};