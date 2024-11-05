class Solution {
public:
int func(vector<int>& nums, int goal){
    int n = nums.size();
    if(goal < 0) return 0;
    int l=0,r=0,count=0,sum=0;
    while(r < n){
        sum += (nums[r]%2);
        while(sum > goal){
            sum -= (nums[l]%2);
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};