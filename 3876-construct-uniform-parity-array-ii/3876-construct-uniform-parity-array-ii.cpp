class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n == 1) return true;
        bool even = false;
        bool odd = false;
        int mini = INT_MAX;
        for(int i=0 ; i<n ; i++){
            mini = min(mini,nums1[i]);
        }
        if(mini&1) odd = true;
        else even = true;
        for(int i=0 ; i<n ; i++){
            if(mini != nums1[i] && odd){
                if((nums1[i]-mini)&1 || nums1[i]&1) continue;
                else return false;
            }
            if(mini != nums1[i] && even){
                if(!((nums1[i]-mini)&1) || !(nums1[i]&1)) continue;
                else return false;
            }
        }
        return true;
    }
};