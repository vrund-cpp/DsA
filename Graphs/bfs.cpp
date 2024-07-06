#include<bits/stdc++.h>
using namespace std;

// Bredth First Search
// queue
// T.C : O(V) + O(2E) ~ O(V) + O(E)
// S.C : O(V) queue + O(V) bfs storing + O(V) vising array ~ O(V)
// value marked before going to queue

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>vis(V,0);
        vector<int>bfs;
        queue<int>q;
        
        vis[0] = 1;
        q.push(0);
        
        while(!q.empty()){
            int f = q.front();  
            q.pop();
            bfs.push_back(f);
            
            for(auto it:adj[f]){
                // without this condition it will be infite loop
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfs;
        
        
    }
};