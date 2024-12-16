class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int smallest=INT_MAX;
        int smallest_index;
        for(int j=0;j<k;j++){
              for(int i=0;i<nums.size();i++){
            if(nums[i]<smallest){
                smallest=nums[i];
                smallest_index=i;
            }
        }
        nums[smallest_index]*=multiplier;
        smallest=INT_MAX;
        }
      return nums;
    }
};