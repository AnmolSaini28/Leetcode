class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        int curr = nums[0];
        for(int i=1 ; i<n ; i++){
            if(nums[i] <= curr){
                curr = nums[i];
            } 
            else{
                res = max(res,nums[i]-curr);
            }
        }
        return res;
    }
};