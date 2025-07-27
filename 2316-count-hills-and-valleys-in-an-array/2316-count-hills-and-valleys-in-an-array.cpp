class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        vector<int> tmp;

        tmp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                tmp.push_back(nums[i]);
            }
        }

        for (int i = 1; i < tmp.size() - 1; i++) {
            if ((tmp[i] > tmp[i - 1] && tmp[i] > tmp[i + 1]) ||
                (tmp[i] < tmp[i - 1] && tmp[i] < tmp[i + 1])) {
                cnt++;
            }
        }

        return cnt;
    }
};