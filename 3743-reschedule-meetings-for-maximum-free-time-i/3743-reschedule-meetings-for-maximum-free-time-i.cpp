class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), r = 0, l = -1, maxGap = 0, curGap = 0;
        while (r < n) {
            curGap += (r == 0 ? startTime[r] : startTime[r] - endTime[r - 1]);
            maxGap = max(maxGap, curGap);
            if (r - l > k) {
                curGap -= (l == -1 ? startTime[l + 1] : startTime[l + 1] - endTime[l]);
                l++;
            }
            r++;
        }
        curGap += (eventTime - endTime[n - 1]);
        maxGap = max(maxGap, curGap);
        return maxGap;
    }
};