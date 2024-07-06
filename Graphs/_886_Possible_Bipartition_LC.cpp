#include<bits/stdc++.h>
using namespace std;

// T.C : O(V+E)
// problem : https://leetcode.com/problems/possible-bipartition/
// solution : https://www.youtube.com/watch?v=0ACfAqs8mm0

class Solution {

private:

    bool isbipartite(int i, vector<int> adj[] , vector<int>&col){
        queue<int>q;
        q.push(i);
        col[i] = 1;

        while(!q.empty()){
            int f = q.front();
            q.pop();

            for(auto it:adj[f]){
                if(col[it] == -1){
                    col[it] = 1 - col[f];
                    q.push(it);
                }
                else if(col[it] == col[f]){
                    return false;
                }
            }
            
        }
        // if whole q is empty that means there is no ambiguity 
        return true;

    }

    // bool dfs(int i, int parent, vector<int> adj[] , vector<int>&vis){
    //     vis[i] = 1;

    //     for(auto it:adj[i]){
    //         if(!vis[it]){
    //             if(dfs(it,i,adj,vis)){
    //                 return true;
    //             }
    //         }
    //         else if(it!=parent){
    //             return true;
    //         }
    //     }
    //     return false;
    // }


public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        
        // cycle detection in undirected graph using dfs
        // this is partially correct approach
        // because even length cycle may be become bipartite graph
        // so our goal is find odd length cycle 


        vector<int> adj[n+1];
        for(int i=0;i<d.size();i++){
            adj[d[i][0]].push_back(d[i][1]);
            adj[d[i][1]].push_back(d[i][0]);
        }

        // in here we use graph coloring
        // if there is odd edge then there is ambiguity
        // that means there is adjecent node with same color

        // we write this loop for multiple components graph
        vector<int>col(n+1,-1);
        for(int i=1;i<col.size();i++){
            if(col[i] == -1){
                if(!isbipartite(i,adj,col)){
                    return false;
                }
            }
        }

        return true;
        
        
    }
};