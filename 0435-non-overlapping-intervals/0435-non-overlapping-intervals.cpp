class Solution {
public:
static bool mycmp(vector<int>& interval1, vector<int>& interval2){
    return interval1[1] < interval2[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(), intervals.end(), mycmp);
        int endTime = intervals[0][1];
        for(int i=1 ; i<n ; i++){
            if(intervals[i][0] >= endTime){
                endTime = intervals[i][1];
            }
            else{
                count++;
            }
        }
        return count;
    }
};