#include<bits/stdc++.h>
using namespace std;

// T.C : O(V+E)
// problem : https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>dis(rooms.size(),0);

        dis[0] = 1;

        queue<int>q;
        q.push(0);

        while(!q.empty()){
            int f = q.front();
            q.pop();

            for(auto it:rooms[f]){
                if(!dis[it]){
                    dis[it] = 1;
                    q.push(it);
                }
            }
        }

        for(int i=0;i<rooms.size();i++){
            if(dis[i] == 0){
                return false;
            }
        }

        return true;
        
    }
};