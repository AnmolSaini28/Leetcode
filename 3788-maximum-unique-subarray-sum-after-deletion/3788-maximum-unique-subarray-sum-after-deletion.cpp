class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> ans;
        int sum=0;
        for (int i:nums){
            ans.insert(i);
        }
        int n=ans.size();
        nums.clear();
        for (int i:ans){
            nums.push_back(i);
        }
        if(n==1){
            return nums[n-1];
        }
        if(nums[n-1]<=0){
            return nums[n-1];
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]<=0){
                break;
            }
            sum+=nums[i];
        }
        return sum;
    }
};