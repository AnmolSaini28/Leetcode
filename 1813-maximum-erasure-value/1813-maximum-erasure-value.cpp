

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int>cumsum(n,0);
        cumsum[0] = nums[0];
        for(int i=1;i<n;i++){
            cumsum[i] = cumsum[i-1]+nums[i];
        }
        vector<int>mp(10001,-1);
        int result =0;
        int i =0,j=0;
        while(j<n){
            i = max(i,mp[nums[j]]+1);
            int jthsum = cumsum[j];
            int ithsum = i-1<0? 0 : cumsum[i-1];
            result = max(result, jthsum - ithsum);
            
            mp[nums[j]] = j;
            j++;
        }
        return result;
    }
};
