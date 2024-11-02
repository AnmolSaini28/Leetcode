class Solution {
public:
    int getMax(vector<int>& nums){
        int n = nums.size();
        int maxi = -1;
        for(int i=0 ; i<n ; i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
    int calculateTotal(vector<int> &v, int threshold) {
    int total = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        total += ceil((double)(v[i]) / (double)(threshold));
    }
    return total;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = getMax(nums);
        while (low <= high) {
        int mid = (low + high) / 2;
        int total = calculateTotal(nums, mid);
        if (total <= threshold) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
    }
};