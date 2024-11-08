class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int sum = 0;
        int n = nums.size();
        vector<int>v(n);
        for(int i=0;i<n;i++){
            sum ^= nums[i];
            v[n-1-i] = pow(2,maximumBit)-1-sum;
        }
        return v;
    }
};