class Solution {
public:
bool calculateTotalHours(vector<int> &v, int mid, int m, int k) {
    int n = v.size();
    int count = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if(v[i] <= mid) count++;
        else{
            res += (count/k);
            count = 0;
        }
    }
    res += (count/k);
    return (res>=m);
}
    int minDays(vector<int>& v, int m, int k) {
        if((long long) v.size() < (long long) m*k) return -1;
        int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        maxi = max(maxi, v[i]);
        mini = min(mini, v[i]);
    }
        int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (calculateTotalHours(v, mid, m, k)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
    }
};