class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        const int n = startTime.size();
        vector<bool> q(n, false);  

        int max_free_left = 0, max_free_right = 0;
        for (int i = 0; i < n; ++i) {
            q[i] = q[i] || ((endTime[i] - startTime[i]) <= max_free_left);
            int free_left = startTime[i] - ((i == 0) ? 0 : endTime[i - 1]);
            max_free_left = max(max_free_left, free_left);
            q[n - i - 1] = q[n - i - 1] || ((endTime[n - i - 1] - startTime[n - i - 1]) <= max_free_right);
            int free_right = ((i == 0) ? eventTime : startTime[n - i]) - endTime[n - i - 1];
            max_free_right = max(max_free_right, free_right);
        }

        int longest = 0;
        for (int i = 0; i < n; ++i) {
            int left = (i == 0) ? 0 : endTime[i - 1];
            int right = (i == n - 1) ? eventTime : startTime[i + 1];
            int gap = right - left - (q[i] ? 0 : endTime[i] - startTime[i]);
            longest = max(longest, gap);
        }

        return longest;
    }
};