class Solution {
public:
int func(vector<int>& nums, int goal){
    int n = nums.size();
    if(goal < 0) return 0;
    int l=0,r=0,count=0,sum=0;
    while(r < n){
        sum += nums[r];
        while(sum > goal){
            sum -= nums[l];
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal)-func(nums,goal-1);
    }
};