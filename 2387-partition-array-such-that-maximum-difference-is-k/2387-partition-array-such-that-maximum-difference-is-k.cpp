class Solution {
public:
    int partitionArray(std::vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        int n = nums.size(), count = 0;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l<n&&r<n&&nums[r]-nums[l]<=k)r++;
            i=r-1;
            count++;
        }
        return count;
    }
};