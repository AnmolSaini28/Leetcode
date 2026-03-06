class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumofEleinArray = 0;
        int sumofFirNEle = n*(n+1)/2;
        for(int i=0 ; i<n ; i++){
            sumofEleinArray += nums[i];
        }
        return sumofFirNEle-sumofEleinArray;
    }
};