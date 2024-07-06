#include<bits/stdc++.h>
using namespace std;

// question : https://leetcode.com/problems/evaluate-division/description/
// solution : https://www.youtube.com/watch?v=GT-qB2FCZ64

class Solution {

private:
    void dfs(string s , string d , unordered_map<string,vector<pair<string,double>>> mp , unordered_map<string,int> &vis , double &ans , double temp){

        // we go from a to b and in b we not want to go back a
        // so for we use this condition

        // if key is exist then count return 1 otherwise 0 in map
        // if we want to find key is exist or not it is more beneficial to use 
        // count instead of find because find return iterator and count return integer

        if(vis.count(s)){
            return;
        }

        if(s == d){
            ans = temp;
            return;
        }

        vis[s] = 1;


        for(auto x:mp[s]){

            // backtracking
            dfs(x.first , d , mp , vis , ans , temp*x.second);
        }

    }


public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {

        // we create map using unordered map
        unordered_map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<e.size();i++){
            mp[e[i][0]].push_back({e[i][1],v[i]});
            mp[e[i][1]].push_back({e[i][0],1.0/v[i]});
        }

        vector<double> finalans;

        for(int i=0;i<q.size();i++){
            string source = q[i][0];
            string dest = q[i][1];

            unordered_map<string,int> vis;
            double ans = -1.0;
            double temp = 1.0;

            
            if(mp.count(source))
            dfs(source , dest , mp , vis , ans , temp);

            finalans.push_back(ans);

        }

        return finalans;
        
    }
};