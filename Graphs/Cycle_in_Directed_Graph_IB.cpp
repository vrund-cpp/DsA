#include<bits/stdc++.h>
using namespace std;

// T.C : O(V + E)

// It is not same as undirected cycle check
// for example please refer solution video

// In here for every path we check cyclic or not
// problem: https://www.interviewbit.com/problems/cycle-in-directed-graph/
// solution: https://www.youtube.com/watch?v=9twcmtQj4DU

int checkcycle(int i,vector<int> Adj[],vector<int>&vis,vector<int>&pathvis){
    vis[i] = 1;
    pathvis[i] = 1;
    
    for(auto it:Adj[i]){
        if(!vis[it]){
            if(checkcycle(it,Adj,vis,pathvis)){
                return 1;
            }
        }
        else if(pathvis[it]){
            return 1;
        }
    }
    
    pathvis[i] = 0;
    return 0;
}


int solve(int A, vector<vector<int> > &B) {
    
    vector<int> Adj[A+1];
    for(int i=0;i<B.size();i++){
        Adj[B[i][0]].push_back(B[i][1]);
    }
    
    vector<int>vis(A+1,0);
    vector<int>pathvis(A+1,0);
    for(int i=1;i<vis.size();i++){
        if(!vis[i]){
            if(checkcycle(i,Adj,vis,pathvis)){
                return 1;
            }
        }
    }
    
    return 0;
     
}
