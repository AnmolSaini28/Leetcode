class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& qt) {
        int n = nums.size();
        vector<int>arr(n,-1);
        arr[0]=0;
        for(int i=1;i<n;i++) {
            if((abs(nums[i]-nums[i-1]))%2) {arr[i]=arr[i-1];}
            else arr[i]=i;
            // cout<<arr[i]<<" ";
        }
        int q = qt.size();
        vector<bool>ans;
        for(int i=0;i<q;i++) {
            if(arr[qt[i][0]]==arr[qt[i][1]]) {
                ans.push_back(true);
            }else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};