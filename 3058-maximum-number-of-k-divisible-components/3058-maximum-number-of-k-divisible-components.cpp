class Solution {
public:
    int fillSum(int node,int k, vector<int>& sum, vector<bool>& vis,
                    unordered_map<int,list<int>>& adj,vector<int>& values){
        vis[node] = true;
        int totalSum = 0;
        for(auto it:adj[node]){
            if(!vis[it]){
                totalSum += fillSum(it,k,sum,vis,adj,values);;
            }
        }
        return sum[node] = (values[node] + totalSum)%k;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,list<int>> adj;
        vector<int> sum(n,0);
        vector<bool> vis(n,false);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt = 0;
        fillSum(0,k,sum,vis,adj,values);
        for(int i=0 ; i<n ; i++){
            if(sum[i]==0) cnt++;
        }
        return cnt;
    }
};