class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int maxOne = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 1){
                curr++;
            }
            else {
                maxOne = max(maxOne,curr);
                curr = 0;
            }
        }
        maxOne = max(maxOne,curr);
        return maxOne;
    }
};