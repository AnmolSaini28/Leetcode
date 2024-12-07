#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(), nums.end());
        int start = 1, end = nums.back();
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (canDivide(nums, maxOperations, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

private:
    bool canDivide(vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > penalty) {
                operations += (balls - 1) / penalty;
            }
            if (operations > maxOperations) return false;
        }
        return true;
    }
};