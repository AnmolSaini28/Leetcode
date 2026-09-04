class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0 ; i<n ; i++){
            maxi = max(maxi,nums[i]);
            mini = nums[i];
            for(int j=i+1 ; j<n ; j++){
                mini = min(mini,nums[j]);
            }
            if(maxi-mini <= k){
                return i;
            }
        }
        return -1;
    }
};