class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        unordered_map<int,int> mp;
        int count = 0;
        long long sum = 0;
        while(i<k) {
            sum+=nums[i];
            count += (mp[nums[i]]==0 ? 1 : 0);
            mp[nums[i]] = i+1;
            i++;
        }
        long long ans = 0;
        if(count==k) {
            ans = max(ans,sum);
        }
        while(i<n) {
            sum+=(nums[i]-nums[i-k]);
            count +=  ( ( mp[nums[i]]<=i-k+1 ? 1 : 0) - ( mp[nums[i-k]]<=i-k+1 ? 1 : 0 ) );
            mp[nums[i]] = i+1;          
            if(count==k) {
                ans = max(ans,sum);
            }
            i++;
        }
        return ans;
    }
};