class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int result = 0;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            if(find(banned.begin(), banned.end(), i) != banned.end()) continue;
            sum += i;
            if(sum > maxSum) break;
            result++;
        }

        return result;
    }
};