class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        bool result=true;
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i+=3){
            vector<int> temp;
            if(nums[i+2]-nums[i]>k){
                result=false;
                break;
            }
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        if(result){
            return ans;
        }
        return {};

    }
};