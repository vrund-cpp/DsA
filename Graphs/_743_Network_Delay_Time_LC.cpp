#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/network-delay-time/
// solution : https://www.youtube.com/watch?v=V6H1qAeB-l4

// Using dijkastra single source shortest path algorithm using priority queue
// T.C : E log(V)
// in case of negative weight it will be infinite loop.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> Adj[n+1];

        for(auto it:times){
            Adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>dis(n+1,1e9);
        dis[k] = 0;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){

            int dist = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it: Adj[node]){
                if(dist + it.second < dis[it.first]){
                    dis[it.first] = dist + it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<dis.size();i++){
            if(dis[i] == 1e9){
                return -1;
            }
            ans = max(ans,dis[i]);
        }

        return ans;
        
    }
};