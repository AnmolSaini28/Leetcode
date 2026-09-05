class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> mx(n,0);
        int mini = INT_MAX;
        int maxi = 0;
        for(int i=n-1 ; i>=0 ; i--){
            mini = min(mini,nums[i]);
            mx[i] = mini;
        }
        for(int i=0 ; i<n ; i++){
            maxi = max(nums[i],maxi);
            if(maxi-mx[i] <= k){
                return i;
            }
        }
        return -1;
    }
};