class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp (n,1);
        vector <int> cnt (n,1);
        int maxLIS = 1;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[j] < nums[i] && dp[i] < 1+dp[j]){
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }
              else if (nums[j] < nums[i] && dp[j] + 1 == dp[i]) {
                cnt[i] = cnt[i] + cnt[j];
            }
            }
            maxLIS = max(maxLIS,dp[i]);
        }
        int noLIS = 0;
        for(int i=0 ; i<n ; i++){
            if(maxLIS == dp[i]){
                noLIS += cnt[i];
            }
        }
        return noLIS;
    }
};