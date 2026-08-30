class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        int minIndex = 0;
        int maxIndex = 0;
        int maxi = nums[0];
        int mini = nums[0];
        for(int i=1 ; i<n ; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxIndex = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                minIndex = i;
            }
        }
        int delfromFront = max(maxIndex,minIndex)+1;
        int delfromBack = n-min(maxIndex,minIndex);
        int delfromBoth = min(n-maxIndex,maxIndex+1) + min(n-minIndex,minIndex+1);
        int ans = min(delfromFront, min(delfromBack, delfromBoth));
        return ans;
    }
};