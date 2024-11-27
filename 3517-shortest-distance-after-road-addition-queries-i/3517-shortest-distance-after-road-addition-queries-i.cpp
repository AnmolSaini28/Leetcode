class Solution {
public:
    int findPath(vector<vector<int>>& adjList, int n, int current,
                 vector<int>& dp) {
        if (current == n - 1)
            return 0;
        if (dp[current] != -1)
            return dp[current];
        int mini = n;
        for (int node : adjList[current]) {
            mini = min(mini, findPath(adjList, n, node, dp) + 1);
        }
        return dp[current] = mini;
    }
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> dp(n, -1);
        vector<vector<int>> adjList(n, vector<int>(0));
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            adjList[queries[i][0]].push_back(queries[i][1]);
            ans.push_back(findPath(adjList, n, 0, dp));
            dp.clear();
            dp.resize(n, -1);
        }
        return ans;
    }
};