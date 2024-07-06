#include<bits/stdc++.h>
using namespace std;

// T.C : O(V + E)
// problem : https://www.interviewbit.com/problems/file-search/

void dfs(int i,vector<int> Adj[],vector<int>&vis){
    vis[i] = 1;
    for(auto it:Adj[i]){
        if(!vis[it]){
            dfs(it,Adj,vis);
        }
    }
}

int breakRecords(int A, vector<vector<int> > &B) {
    vector<int> Adj[A+1];
    
    for(int i=0;i<B.size();i++){
        Adj[B[i][0]].push_back(B[i][1]);
        Adj[B[i][1]].push_back(B[i][0]);
    }
    
    vector<int>vis(A+1,0);
    
    int ans = 0;
    for(int i=1;i<vis.size();i++){
        if(!vis[i]){
            ans++;
            dfs(i,Adj,vis);
        }
    }
    
    return ans;
}
