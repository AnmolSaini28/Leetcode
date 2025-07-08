class Solution {
private:
    int check(vector<vector<int>>&nums, int i)
    {
        int s = i+1;
        int e = nums.size()-1;

        int idx = nums.size();
        
        while(s <= e)
        {
            int mid = s+(e-s)/2;

            if(nums[i][1] >= nums[mid][0])
            s = mid+1;

            else
            {
                idx = mid;
                e = mid-1;
            }
        }
        return idx;
    }
public:
    int maxValue(vector<vector<int>>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
       
        for(int i = n-1; i >= 0; i--)
        {
            for(int l = 1; l <= k; l++)
            {
                int idx = check(nums, i);
                
                int take = nums[i][2] + dp[idx][l-1];
                int notTake = dp[i+1][l];
                dp[i][l] = max(take, notTake);
            }
        }
        return dp[0][k];
    }
};