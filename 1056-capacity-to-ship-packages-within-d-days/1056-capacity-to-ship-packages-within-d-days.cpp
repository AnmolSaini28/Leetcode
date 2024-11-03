class Solution {
    private:
    bool calculateDays(vector<int>& weights, int days, int mid){
        int n = weights.size();
        int count = 1;
        int cap = 0;
        for(int i=0 ; i<n ; i++){
            if(cap + weights[i] > mid){
                count++;
                cap = weights[i];
            }
            else{
                cap += weights[i];
            }
        }
        return (count <= days);
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int ans = -1;
        for(int i=0 ; i<n ; i++){
            sum += weights[i];
        }
        if(days == 1) return sum;
        int low = *max_element(weights.begin(), weights.end());;
        int high = sum;
        while(low <= high){
            int mid = (low+high)/2;
            if(calculateDays(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};