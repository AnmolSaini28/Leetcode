class Solution {
public:
    int count = 0;
    int maxOr = 0;

    void dfs(vector<int>& nums, int index, int currOr) {
        if (index == nums.size()) {
            if (currOr == maxOr) count++;
            return;
        }
        
        dfs(nums, index + 1, currOr | nums[index]);

       
        dfs(nums, index + 1, currOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums) {
            maxOr |= num;
        }

        dfs(nums, 0, 0);
        return count;
    }
};