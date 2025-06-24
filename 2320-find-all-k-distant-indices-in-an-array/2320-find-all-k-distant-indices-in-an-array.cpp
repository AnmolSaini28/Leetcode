class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        int N=nums.size(), start=0;
        for(int i=0; i<N; i++){
            if(nums[i]==key){
                int low=max(0,i-k), high=min(i+k,N-1);
                while(start<=high){
                    if(low<=start) ans.push_back(start);
                    start++;
                }
            }
        }
        return ans;
    }
};