#include<bits/stdc++.h>
using namespace std;

// T.C : 

// Dfs
// problem: https://www.interviewbit.com/problems/knight-on-chess-board/
// solution: https://www.youtube.com/watch?v=9-rOWC6-S08&t=346s


int knight(int A, int B, int C, int D, int E, int F) {
    
    vector<vector<bool>> vis(A+1,vector<bool>(B+1,0)); 
    queue<pair<int,int>>q;
    
    q.push({C,D});
    vis[C][D] = 1; 

    int dx[] = {-2,2,-2,2,1,1,-1,-1};
    int dy[] = {1,1,-1,-1,2,-2,2,-2};
    int cnt = 0;
    
    while(!q.empty()){
        
        int size = q.size();
        
        for(int j=0;j<size;j++){
            
            int f1 = q.front().first;
            int f2 = q.front().second;
            q.pop();
        
            if(f1 == E && f2 == F){
                return cnt;
            }
            
            for(int i=0;i<8;i++){
                if(f1+dx[i]>0 && f1+dx[i]<=A && f2+dy[i]>0 && f2+dy[i]<=B && vis[f1+dx[i]][f2+dy[i]] == 0){
                    vis[f1+dx[i]][f2+dy[i]] = 1;
                    q.push({f1+dx[i],f2+dy[i]});    
                }
            }            
        }
        
        cnt++;
        
    }
    
    return -1;
}
