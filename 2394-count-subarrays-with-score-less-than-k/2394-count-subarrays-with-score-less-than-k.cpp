class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    long long res = 0, sum = 0, n = nums.size();
    for (int i = 0, j = 0; i < n; i++) {
        sum += nums[i];
        while (sum * (i - j + 1) >= k)
            sum -= nums[j++];
        res += i - j + 1;
    }
    return res;
}
};