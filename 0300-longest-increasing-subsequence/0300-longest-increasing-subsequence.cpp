class Solution {
    private:
    int ceilIndex(vector<int>& res , int l , int r , int x){
        while(r > l){
            int mid = l + (r-l)/2;
            if(res[mid] >= x){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return r;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> res;
        res.push_back(nums[0]);
        for(int i=1 ; i<n ; i++){
            if(nums[i] > res[res.size()-1]){
                res.push_back(nums[i]);
            }
            else {
                int index = ceilIndex(res,0,res.size()-1,nums[i]);
                res[index] = nums[i];
            }
        }
        return res.size();
    }
};