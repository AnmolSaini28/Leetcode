class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() < k) return {};

        vector<int> result(nums.size() - k + 1, 0);
        int a = 0;

        for (int i = 0, j = k - 1; j < nums.size(); i++, j++) {
            if (isConsecutive(nums, i, j)) {
                result[a++] = nums[j];
            } else {
                result[a++] = -1;
            }
        }

        return result;
    }

private:
    bool isConsecutive(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; i++) {
            if (nums[i] + 1 != nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};