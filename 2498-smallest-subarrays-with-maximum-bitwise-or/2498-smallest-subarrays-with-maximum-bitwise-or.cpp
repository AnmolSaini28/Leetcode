class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0), pos(31,-1);

        int j;
        for(int i = n-1; i >= 0; i--){
            j = i;
            for(int b = 0; b < 31; b++){
                if(nums[i]&(1<<b))
                    pos[b] = i;
                else
                    j = max(j, pos[b]);
            }

            ans[i] = j - i + 1;
        }

        
        return ans;
    }
};